
sumTwoFirstElements :: [Float] -> Float
sumTwoFirstElements [] = 0
sumTwoFirstElements (x:[]) = x
sumTwoFirstElements (x:xs) = x + head xs
