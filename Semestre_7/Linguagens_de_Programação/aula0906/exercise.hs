ex1 :: Int -> Int -> Int
ex1 m n = if m == n
            then m
            else m * (m+1) * ex1 m (n-1)


