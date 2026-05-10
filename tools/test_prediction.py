import sys, os
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))
from model_utils import load_model_and_vocab, tokenize_code_full, predict, predict_code_full, graphcodebert_available
import torch

DEVICE=torch.device('cuda' if torch.cuda.is_available() else 'cpu')
model,stoi,id2label,max_line= load_model_and_vocab('modèle/models/best_model.pt','Données/vocab.pkl',DEVICE)
code = '#include <stdio.h>\nint main() {\n    printf("Hello")\n    return 0\n}\n'
print('=== TEST CODE ===')
print(code)

print('\n--- Local model predictions ---')
toks, lines = tokenize_code_full(code)
errs = predict(model,toks,lines,stoi,id2label,max_line,DEVICE,confidence_threshold=0.5)
print(errs)

print('\n--- GraphCodeBert predictions ---')
if graphcodebert_available(DEVICE):
    print(predict_code_full(code, DEVICE, confidence_threshold=0.5, id2label_override=id2label))
else:
    print('GraphCodeBert unavailable')
