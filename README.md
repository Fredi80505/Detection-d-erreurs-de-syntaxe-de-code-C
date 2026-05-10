# Détection d'erreurs syntaxiques en langage C par TALN

## Contexte et objectif

Le langage C est exigeant syntaxiquement : une simple absence de point-virgule peut empêcher l’exécution du code. Ce projet vise à développer un modèle de traitement automatique des langues naturelles (TALN) capable d’analyser un fichier source C, de détecter les erreurs de syntaxe et de localiser précisément la ligne où l’erreur se produit. Deux approches sont explorées :

1. **Modèle CNN‑BiLSTM with attention** – architecture personnalisée.
2. **Fine‑tuning de GraphCodeBERT** – modèle pré‑entraîné pour le code.

## Structure du dépôt

├── app.py # Interface Flask pour la prédiction
├── model_utils.py # Chargement et inférence des modèles
├── model.py # Définition du modèle CNN‑BiLSTM
├── requirements.txt # Dépendances Python
├── Données/ # Dossiers contenant les données brutes et traitées
│ ├── Codes_valides/ # Fichiers C corrects
│ ├── Codes_invalides/ # Fichiers C avec erreurs injectées
│ └── Données_étiquettes/ # Fichiers JSON contenant les labels (tokens, erreurs, lignes)
├── modèle/ # Modèles sauvegardés
│ └── models/
│ ├── local/ # Meilleur modèle CNN‑BiLSTM
│ └── graph_codebert/ # Modèle GraphCodeBERT fine‑tuné
├── résultats/ # Courbes, matrices, métriques
└── README.md



## Jeu de données

- **Source** : Environ 15 000 fichiers C issus de GitHub (divers projets).
- **Longueur** : de quelques dizaines à 574 lignes par fichier.
- **Augmentation par injection d’erreurs** : 10 classes d’erreurs sont synthétisées (point‑virgule manquant/en trop, parenthèse/accolade manquante, opérateur incorrect, fautes de frappe, directive mal formée, etc.).
- **Vocabulaire** : 114 783 tokens (dont `<PAD>`, `<UNK>`, `<DEL>`).
- **Séparation** : 80% entraînement, 10% validation, 10% test (répartition par fichiers).

## Architecture du modèle CNN‑BiLSTM + Attention

Le modèle combine plusieurs modules pour capturer les dépendances locales et globales :

- **Embeddings** : tokens + types de tokens (identifiants, mots‑clés, ponctuation…).
- **CNN 1D** : trois filtres de tailles différentes (3,5,7) → extraction de motifs locaux.
- **BiLSTM** : deux couches bidirectionnelles pour le contexte séquentiel.
- **Multi‑Head Self‑Attention** : quatre têtes avec connexion résiduelle pour les relations à longue distance.
- **Deux têtes de sortie** :
  - Classification de l’erreur (8 classes après fusion des typos).
  - Prédiction du numéro de ligne (0 à 575).

**Paramètres clés** :
- `embedding_dim = 128`, `type_embedding_dim = 64`
- `num_filters = 64`, `filter_sizes = (3,5,7)`
- `hidden_dim = 128`, `num_layers = 2`
- `num_heads = 4`, `dropout = 0.3`

## Entraînement

- **Fonction de perte** : Focal Loss (γ=2) + pondération `sqrt(inverse_freq)` des classes.
- **Optimiseur** : AdamW (`lr=1e-3`, `weight_decay=1e-4`).
- **Scheduler** : OneCycleLR (max_lr=1e-3, 30 époques).
- **Early stopping** : basé sur le F1 macro (patience=8).
- **Sampling** : WeightedRandomSampler pour rééquilibrer les classes rares.

## Évaluation du modèle CNN‑BiLSTM

| Métrique | Valeur |
|----------|--------|
| Loss (test) | 1.2923 |
| Accuracy (test) | 0.8221 |
| F1 macro | 0.68 |
| Meilleur AUC | 1.000 (EXTRA_SEMICOLON) |

Les résultats détaillés (rapport de classification, matrice de confusion, courbes ROC) sont disponibles dans le dossier `résultats/`.

> **Remarque** : La classe `KEYWORD_TYPO` reste difficile (`F1=0.00`, `AUC=0.72`). Des confusions persistent entre certaines erreurs de mots‑clés et les tokens corrects.

## Fine‑tuning de GraphCodeBERT

- **Modèle** : `microsoft/graphcodebert-base`
- **Task** : classification de chaque ligne de code (mêmes 8 classes).
- **Entraînement** : 3 époques, batch size 16, LR=2e‑5.
- **Résultats** : meilleure précision que CNN‑BiLSTM, mais temps d’entraînement plus long.

Le modèle fine‑tuné est sauvegardé dans `modèle/models/graph_codebert/`.

## Interface de prédiction (Flask)

L’application `app.py` permet de tester les deux modèles via une interface web.

### Lancement

```bash
conda activate pytorch311   # ou votre environnement Python
python app.py


pip install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cu118   # adaptez CUDA
pip install flask transformers datasets scikit-learn matplotlib seaborn tqdm pycparser


flask
torch
transformers
datasets
scikit-learn
matplotlib
seaborn
tqdm
pycparser



Auteur
BARGO Alfred – Projet de TALN
