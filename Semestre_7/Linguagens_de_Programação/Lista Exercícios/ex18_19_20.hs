data Produto = Perecivel Int String Int Bool Type
 | Nao_Perecivel Int String String Int Type
 deriving Show

data Type = Unidade | Peso
 deriving Show

isValid :: Produto -> Int -> Bool
isValid produto currentYear = case produto of
	Perecivel code description expirationDate isEdible prodType -> if currentYear - expirationDate < 0 then True else False
	Nao_Perecivel code description manufacturer yearOfManufacture prodType -> True