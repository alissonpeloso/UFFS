sumList :: [Float] -> Float
sumList [] = 0
sumList (x:xs) = x + (sumList xs)