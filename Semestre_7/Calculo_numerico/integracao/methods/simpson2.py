from methods.method import Method
import numpy as np

# 2º Método de Simpson: n = 4 + 3 * m , m = 0,1,2,3,4,...


class Simpson2(Method):
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
            elif (i % 3) == 0:
                amount += 2*y[i]
            else:
                amount += 3*y[i]

        A = 3 * h / 8 * amount
        print("A =", A)
