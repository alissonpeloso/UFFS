from methods.matricial import Matricial

A = [[1, 1991, 1991**2, 1991**3], [1, 1994, 1994 ** 2, 1994**3],
     [1, 2000, 2000**2, 2000**3], [1, 2010, 2010**2, 2010**3]]
y = [0.525, 0.58, 0.682, 0.79]

matricial = Matricial(A, y)
matricial.solve()
