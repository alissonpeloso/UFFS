def med(x,y):
    r = (x+y)/2
    return r

def min(x,y):
    if x > y:
        return x
    if x == y:
        return x
    if y > x:
        return y

def fat(x):
    r = 1
    for i in range(2,x+1):
        r*=i
    return r

def prime(x):
    b = True
    n = int(x**0.5)
    for i in range(2,n+1):
        if x % i == 0:
            b = False
    return b

def gem(x,y):
    if abs(x-y) == 2:
        return True
    else:
        return False

def solve(l1,l2):
    s=[]
    cont = 0
    for i in range(len(l1)-1,-1,-1):
        if i > 0:
            r = l1[i]+l2[i]+cont
            cont = 0
            if r > 9:
                r-=10
                cont+=1
            s.append(r)
        else:
            r = l1[i]+l2[i]+cont
            s.append(r)
    s.reverse()
    return s

def perf(x):
    som = 0
    for i in range(1,(x//2)+1):
        if x % i == 0:
            som+=i
    if som == x:
        return 1
    else:
        return 0

def lmed(l):
    soma = 0
    for i in range(len(l)):
        soma += l[i]
    r = soma / len(l)
    return r
