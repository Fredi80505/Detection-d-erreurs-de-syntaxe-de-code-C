/* ==================================================
   DOM ELEMENTS
   ================================================== */
const codeInputContainer = document.getElementById('codeInput');
const modelSelect = document.getElementById('modelSelect');
const submitBtn = document.getElementById('submitBtn');
const clearBtn = document.getElementById('clearBtn');
const loadingState = document.getElementById('loadingState');
const emptyState = document.getElementById('emptyState');
const resultContainer = document.getElementById('resultContainer');
const successMessage = document.getElementById('successMessage');
const errorsList = document.getElementById('errorsList');
const errorSummary = document.getElementById('errorSummary');
const charCount = document.getElementById('charCount');
const modelDesc = document.getElementById('modelDesc');
const statusIndicator = document.getElementById('statusIndicator');

/* ==================================================
   CODE EDITOR - CodeMirror Instance
   ================================================== */
let codeEditor = null;

/* ==================================================
   MODEL DESCRIPTIONS
   ================================================== */
const modelDescriptions = {
    custom: '🧠 Modèle personnalisé basé sur notre entraînement - Optimisé pour nos données',
    graphcodebert: '🌐 GraphCodeBert pré-entraîné - Modèle IA avancé pour l\'analyse de code'
};

/* ==================================================
   INITIALIZATION
   ================================================== */
document.addEventListener('DOMContentLoaded', function() {
    initializeCodeEditor();
    initializeEventListeners();
    updateCharCount();
});

function initializeCodeEditor() {
    // Initialize CodeMirror editor
    codeEditor = CodeMirror(codeInputContainer, {
        lineNumbers: true,
        mode: 'text/x-csrc', // C language mode
        theme: 'dracula', // Thème sombre avec bon contraste
        indentUnit: 4,
        indentWithTabs: false,
        autoIndent: true,
        smartIndent: true,
        matchBrackets: true,
        autoCloseBrackets: true,
        lineWrapping: true,
        styleActiveLine: true,
        highlightSelectionMatches: { showToken: /\w/, annotateScrollbar: true }
    });

    // Add placeholder functionality
    const placeholder = '// Collez votre code C ici...\n#include <stdio.h>\nint main() {\n    printf("Hello");\n    return 0;\n}';
    if (codeEditor.getValue() === '') {
        codeEditor.setValue(placeholder);
    }

    // Update character count on input
    codeEditor.on('change', updateCharCount);
    
    // Handle keyboard shortcuts
    codeEditor.setOption('extraKeys', {
        'Ctrl-Enter': handleSubmit,
        'Cmd-Enter': handleSubmit
    });
}

function initializeEventListeners() {
    // Model select events
    modelSelect.addEventListener('change', updateModelDescription);

    // Button events
    submitBtn.addEventListener('click', handleSubmit);
    clearBtn.addEventListener('click', clearForm);

    // Initial model description
    updateModelDescription();
}

/* ==================================================
   CHARACTER COUNT
   ================================================== */
function updateCharCount() {
    const count = codeEditor.getValue().length;
    charCount.textContent = count.toLocaleString();
}

/* ==================================================
   MODEL DESCRIPTION
   ================================================== */
function updateModelDescription() {
    const selectedModel = modelSelect.value;
    modelDesc.textContent = modelDescriptions[selectedModel] || 'Sélectionnez un modèle';
}

/* ==================================================
   FORM SUBMISSION
   ================================================== */
async function handleSubmit() {
    const code = codeEditor.getValue().trim();
    const model = modelSelect.value;

    // Validation
    if (!code) {
        showNotification('Veuillez entrer du code à analyser', 'error');
        return;
    }

    if (code.length > 50000) {
        showNotification('Le code dépasse la limite de 50 000 caractères', 'error');
        return;
    }

    // UI state
    setLoading(true);
    updateStatus('Analyse en cours...', false);

    try {
        const response = await fetch('/predict', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({ code, model })
        });

        if (!response.ok) {
            throw new Error(`Erreur serveur: ${response.status}`);
        }

        const data = await response.json();
        displayResults(data, code);
        updateStatus('Prêt', true);

    } catch (error) {
        console.error('Error:', error);
        showNotification(`Erreur : ${error.message}`, 'error');
        updateStatus('Prêt', true);
    } finally {
        setLoading(false);
    }
}

/* ==================================================
   DISPLAY RESULTS
   ================================================== */
function displayResults(data, code) {
    emptyState.style.display = 'none';
    resultContainer.style.display = 'flex';

    // Success message or errors
    if (data.errors && data.errors.length > 0) {
        successMessage.style.display = 'none';
        displayErrors(data.errors);
        displaySummary(data.errors, code);
    } else {
        // no errors returned; check if the backend sent a message (e.g. modèle indisponible)
        if (data.message && data.message.toLowerCase().includes('graphcodebert')) {
            // show warning instead of standard success
            successMessage.innerHTML = `
                <i class="fas fa-exclamation-triangle"></i>
                <span id="successText">${escapeHtml(data.message)}</span>
            `;
            successMessage.classList.remove('alert-success');
            successMessage.classList.add('alert-warning');
            successMessage.style.display = 'flex';
        } else {
            displaySuccessMessage();
        }
        errorsList.innerHTML = '';
        errorSummary.innerHTML = '';
    }
}

/* ==================================================
   DISPLAY SUCCESS MESSAGE
   ================================================== */
function displaySuccessMessage() {
    successMessage.innerHTML = `
        <i class="fas fa-check-circle"></i>
        <span id="successText">✓ Aucune erreur détectée - Votre code est valide !</span>
    `;
    successMessage.style.display = 'flex';
}

/* ==================================================
   DISPLAY ERRORS
   ================================================== */
function displayErrors(errors) {
    errorsList.innerHTML = '';
    
    // Sort errors by line
    const sortedErrors = [...errors].sort((a, b) => a.line - b.line);

    sortedErrors.forEach((error, index) => {
        const errorItem = createErrorItem(error);
        errorsList.appendChild(errorItem);
        
        // Stagger animation
        setTimeout(() => {
            errorItem.style.animation = `slideIn 0.3s ease-out`;
        }, index * 50);
    });
}

function createErrorItem(error) {
    const div = document.createElement('div');
    div.className = 'error-item';

    const confidence = (error.confidence * 100).toFixed(0);
    const confidenceLevel = getConfidenceLevel(error.confidence);

    div.innerHTML = `
        <div class="error-header">
            <span class="error-line">Ligne ${error.line}</span>
            <span class="error-type">${escapeHtml(error.type)}</span>
            <span class="confidence-badge confidence-${confidenceLevel}">
                ${confidence}% confiance
            </span>
        </div>
    `;

    return div;
}

function getConfidenceLevel(confidence) {
    if (confidence >= 0.8) return 'high';
    if (confidence >= 0.5) return 'medium';
    return 'low';
}

/* ==================================================
   DISPLAY SUMMARY
   ================================================== */
function displaySummary(errors, code) {
    const lineCount = code.split('\n').length;
    const errorCount = errors.length;
    const errorRate = ((errorCount / lineCount) * 100).toFixed(1);

    const highConfidence = errors.filter(e => e.confidence >= 0.8).length;
    const mediumConfidence = errors.filter(e => e.confidence >= 0.5 && e.confidence < 0.8).length;
    const lowConfidence = errors.filter(e => e.confidence < 0.5).length;

    errorSummary.innerHTML = `
        <div class="summary-title">
            <i class="fas fa-chart-bar"></i>
            Résumé de l'analyse
        </div>
        <div class="summary-stats">
            <div class="stat-item">
                <div class="stat-value">${errorCount}</div>
                <div class="stat-label">Erreurs détectées</div>
            </div>
            <div class="stat-item">
                <div class="stat-value">${lineCount}</div>
                <div class="stat-label">Lignes de code</div>
            </div>
            <div class="stat-item">
                <div class="stat-value">${errorRate}%</div>
                <div class="stat-label">Taux d'erreur</div>
            </div>
            <div class="stat-item">
                <div class="stat-value">${highConfidence}</div>
                <div class="stat-label">Haute confiance</div>
            </div>
        </div>
    `;
}

/* ==================================================
   LOADING STATE
   ================================================== */
function setLoading(isLoading) {
    if (isLoading) {
        loadingState.style.display = 'flex';
        resultContainer.style.display = 'none';
        submitBtn.classList.add('loading');
        submitBtn.disabled = true;
    } else {
        loadingState.style.display = 'none';
        submitBtn.classList.remove('loading');
        submitBtn.disabled = false;
    }
}

/* ==================================================
   STATUS INDICATOR
   ================================================== */
function updateStatus(status, isReady) {
    const statusDot = statusIndicator.querySelector('.status-dot');
    const statusText = statusIndicator.querySelector(':not(.status-dot)');

    if (isReady) {
        statusDot.style.backgroundColor = '#10b981';
    } else {
        statusDot.style.backgroundColor = '#f59e0b';
    }

    // Update text while preserving the dot
    const newHTML = `<span class="status-dot"></span>${status}`;
    statusIndicator.innerHTML = newHTML;
}

/* ==================================================
   CLEAR FORM
   ================================================== */
function clearForm() {
    codeEditor.setValue('');
    emptyState.style.display = 'flex';
    resultContainer.style.display = 'none';
    updateCharCount();
    codeEditor.focus();
}

/* ==================================================
   NOTIFICATIONS
   ================================================== */
function showNotification(message, type = 'info') {
    const notification = document.createElement('div');
    notification.className = `alert alert-${type === 'error' ? 'error' : 'success'}`;
    notification.style.position = 'fixed';
    notification.style.top = '80px';
    notification.style.right = '20px';
    notification.style.zIndex = '2000';
    notification.style.maxWidth = '400px';

    let icon = type === 'error' ? 'fa-times-circle' : 'fa-check-circle';
    notification.innerHTML = `
        <i class="fas ${icon}"></i>
        <span>${escapeHtml(message)}</span>
    `;

    document.body.appendChild(notification);

    // Auto-remove after 5 seconds
    setTimeout(() => {
        notification.style.opacity = '0';
        notification.style.transform = 'translateX(400px)';
        notification.style.transition = 'all 0.3s ease';
        setTimeout(() => notification.remove(), 300);
    }, 5000);
}

/* ==================================================
   UTILITY FUNCTIONS
   ================================================== */
function escapeHtml(unsafe) {
    return unsafe
        .replace(/&/g, '&amp;')
        .replace(/</g, '&lt;')
        .replace(/>/g, '&gt;')
        .replace(/"/g, '&quot;')
        .replace(/'/g, '&#039;');
}