fatorial :: Integer -> Integer
fatorial 2 = 2
fatorial n = fatorial (n -1 ) * n

mul :: Int -> Int -> Int
-- mul m n
--  | n == 0 = 0
--  | n > 0 = m + mul m (n-1)
mul m 0 = 0
mul m n = m + mul m (n-1)