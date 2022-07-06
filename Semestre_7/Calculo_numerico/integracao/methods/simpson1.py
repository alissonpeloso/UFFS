from methods.method import Method
import numpy as np

# 1º Método de Simpson, n = 3,5,7,...


class Simpson1(Method):
    def __init__(self, f: str, a: float, b: float, n: int) -> None:
        super().__init__(f, a, b, n)
        self.solve()

    def solve(self):
        a = self.a
        b = self.b
        n = self.n
        f = self.func

        h = abs(b - a) / (n-1)
        x = list(np.linspace(a, b, n))
        y = [f(i) for i in x]

        amount = 0
        for i in range(len(y)):
            if i == 0 or i == len(y)-1:
                amount += y[i]
            elif (i % 2) != 0:
                amount += 4*y[i]
            else:
                amount += 2*y[i]

        A = h / 3 * amount
        print("A =", A)
