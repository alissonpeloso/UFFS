def exp(a, e, m):
    res = 1
    for i in range(e):
        res = res * a % m
    return res


def expBin(a, e, m):
    if e == 0:
        return 1
    if e % 2 == 0:
        x = expBin(a, e//2, m)
        return x*x%m
    x = expBin(a, e//2, m)
    return a*x*x%m
