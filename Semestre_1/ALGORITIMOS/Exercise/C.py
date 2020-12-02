def multm(m1,m2):
    m3 = []
    if len(m1[0]) == len(m2):
        for c in range(len(m1)):
            lin=[]
            for d in range(len(m2[0])):
                soma = 0
                for k in range(len(m2)):
                    soma+=m1[c][k]*m2[k][d]
                lin.append(soma)
            m3.append(lin)
        return m3
    else:
        return -1

a1 = [[1,2],[2,1],[3,1]]
a2 = [[1,2,1],[2,1,2]]

print(multm(a1,a2))
