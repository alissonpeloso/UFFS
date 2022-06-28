pow :: Float -> Int -> Float
pow _ 0 = 1
pow x n = x * (pow x (n-1))