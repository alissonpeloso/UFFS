module Main (main) where

main :: IO ()
main = do putStrLn "Digite um número: "
          n1 <- readLn
          putStrLn "Digite outro número: "
          n2 <- readLn
          putStr "Soma dos números digitados: "
          putStrLn (show (n1 + n2))



dobro x = x + x

quadruplo x = dobro (dobro x)

areaCirculo r = pi * r**2

vabs :: Integer -> Integer
vabs n | n >= 0 = n
       | n < 0 = -n

sinal :: Int -> Int
sinal n | n < 0  = -1
        | n == 0 =  0
        | otherwise =  1

areaTriangulo a b c = let s = (a + b + c) / 2
                        in sqrt (s * (s-a) * (s-b) * (s-c))

areaTriangulo' a b c = sqrt (s * (s-a) * (s-b) * (s-c))
    where 
        s = (a + b + c) / 2

minhaFuncao x = 3 + f x + f a + f b
    where
        f x = x + 7 * c
        a = 3 * c
        b = f 2
        c = 10

firstOrEmpty :: [String] -> String
firstOrEmpty lst =  if not (null lst)
                    then head lst
                    else "empty"

firstOrEmpty' [] = "empty"
firstOrEmpty' lst = head lst



