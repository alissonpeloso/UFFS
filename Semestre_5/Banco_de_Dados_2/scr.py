import re;
arquivo = open('nomearq', 'r')
arquivoList = list(arquivo)
REDO = []

checkValue = re.compile(r'T[0-9]*,', re.IGNORECASE)
commit = re.compile(r'commit', re.IGNORECASE)
extract = re.compile(r'(?!commit\b)(?!CKPT\b)(?!Start\b)\b\w+', re.IGNORECASE)]
words = re.compile(r'\w+', re.IGNORECASE)

valores = words.findall(arquivoList[0])
variaveis = {}
for i in range(0, len(valores), 2):
    variaveis[valores[i]] = valores[i+1]
del valores
print("", variaveis)
end = 0

for linha in reversed(arquivoList):
    if commit.search(linha):
        REDO.append(extract.findall(linha[0]))

print("Aplicando REDO:", REDO, "\n")

for j in range(l, len(arquivoList) - 1, 1):
    linha = arquivoList[j]
    if (checkValue.search(linha)):
        if(extract.findall(linha)[0] in REDO):
            variaveis[words.findall(linha)[1]] = words.findall(linha)[2]

print("Resultado:", variaveis)
arquivo.close()