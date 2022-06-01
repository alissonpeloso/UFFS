import numpy as np


class Method:
    def __init__(self, A, b, epsilon) -> None:
        self.A = np.array(A)
        self.b = np.array(b)
        self.episolon = epsilon
        self.verify()

    def isDDM(self):
        m = self.A
        n = self.A.shape[0]

        for i in range(0, n):
            sum = 0

            for j in range(0, n):
                sum = sum + abs(m[i][j])
            sum = sum - abs(m[i][i])

            if (abs(m[i][i]) < sum):
                return False

        return True

    def verify(self):
        if(self.A.shape[0] != self.A.shape[1]):
            print("A matriz deve ser Quadrada")
            exit(1)
        if(self.A.shape[0] != self.b.shape[0]):
            print("O vetor b deve ter dimensão nx1")
            exit(1)
        if(np.linalg.det(self.A) == 0):
            print("A matriz A não pode ser singular")
            exit(1)
        if(not self.isDDM()):
            print("A matriz A não possui diagonal dominante")
            exit(1)

    def getDiagonal1(self):
        A = self.A
        b = self.b
        AA = self.A.copy()
        bb = self.b.copy()

        for i in range(A.shape[0]):
            for j in range(A.shape[1]):
                AA[i][j] = A[i][j]/A[i][i]
            bb[i] = b[i]/A[i][i]

        return AA, bb
