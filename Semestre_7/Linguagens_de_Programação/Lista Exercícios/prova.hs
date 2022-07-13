p1 = if 1 == 2 then "abc" else ['d', 'e', 'f']

p2 = let pot_dois x | x <= 0 = 1
                    | otherwise = 2 * pot_dois (x -1)
        in pot_dois 6

-- Esse dá erro
p3 = case not (1 /= 2) of
        True -> "3" -- 3
        False -> "fim" 

p4 = filter (not . even . (+3)) [5,6,7,8,9]

p5 = sum (map (logBase 3) [9, 27, 81])

--------------------------

data DescMov = Abertura | Saque | Deposito
 deriving Show
type Data = String
type Movimento = (Data, DescMov, Double, Double)
type Histórico = [ Movimento ]

exemplo :: Histórico
exemplo = [("1/2/18", Abertura, 100, 0),
	("6/6/18", Deposito, 20, 100),
	("6/5/18", Saque, 80, 120),
	("3/4/18", Deposito, 50, 40),
	("5/5/18", Deposito, 35, 90),
	("9/2/18", Saque, 5, 125),
	("4/2/18", Deposito, 2, 120),
	("4/2/18", Deposito, 18, 122)]

somaDepósitos :: Histórico -> Double
somaDepósitos hist = foldl (\amont (_, _, value, _) -> amont+value) 0 depHist
 where
	depHist = filter isDeposito hist

isSaque :: Movimento -> Bool
isSaque (_, Saque, _, _) = True
isSaque (_, _, _, _) = False

isDeposito :: Movimento -> Bool
isDeposito (_, Deposito, _, _) = True
isDeposito (_, _, _, _) = False

exD :: [Conta] -> [(Int, Double)]
exD contas = map (depPerSaque) contas

depPerSaque :: Conta -> (Int, Double)
depPerSaque (Conta id hist) = (id,  (somaDepósitos hist) - (somaSaques hist))

somaSaques :: Histórico -> Double
somaSaques hist = foldl (\amont (_, _, value, _) -> amont+value) 0 depHist
 where
	depHist = filter isSaque hist 

data Conta = Conta Int Histórico

letraA = somaDepósitos exemplo

letraB = filter (isSaque) exemplo

letraC = Conta 01 exemplo

ac1 = Conta 1 exemplo
ac2 = Conta 2 exemplo

letraD = exD [  ac1, ac2]