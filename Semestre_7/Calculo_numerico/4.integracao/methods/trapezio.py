from methods.method import Method
import numpy as np

# Método dos Trapézios (1/2)


class Trapezio(Method):
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
            else:
                amount += 2*y[i]

        A = h / 2 * amount
        print("A =", A)
