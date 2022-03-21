class stru:
    nomep = ''
    nvit = 0
    nder = 0
    nemp = 0

def solve1(l):
    for i in range(5):
        st = stru()
        st.nomep=str(input('Nome do País: '))
        st.nvit=int(input('Número de Vitórias: '))
        st.nder=int(input('Número de Derotas: '))
        st.nemp=int(input('Número de Empates: '))
        l.append(st)


def solve2(l):
    mpont = 0
    posi = -1
    v = []
    s = []
    for i in range(len(l)):
        som = 0
        som = (3*l[i].nvit) + (l[i].nemp)
        if som > mpont:
            mpont = som
            posi = i
    for i in range(len(l)):
        som = 0
        som = (3*l[i].nvit) + (l[i].nemp)
        if som == mpont:
            v.append(i)
    for i in range(len(v)):
        s.append(l[i].nomep)
    return s

abc = []

solve1(abc)

print(solve2(abc))
