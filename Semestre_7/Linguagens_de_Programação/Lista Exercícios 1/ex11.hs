doubleFactorial :: Int -> Int
doubleFactorial 1 = 1
doubleFactorial 2 = 2
doubleFactorial n = n * doubleFactorial(n-2)