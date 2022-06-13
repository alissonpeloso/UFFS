module Exercicíos where

ex1 = a 
    where
        a = (4, "Ola", True)

ex2 = snd (fst a)
    where 
        a = (("Hello", 4), True)

-- ex4

data Cliente = OrgGov String
             | Empresa String Integer String String
             | Individuo Pessoa Bool
             deriving Show

data Pessoa = Pessoa String String Genero
            deriving Show

data Genero = Masculino | Feminino | Outro
            deriving Show

getNomePessoa :: Pessoa -> String
getNomePessoa (Pessoa fn ln _) = fn ++ " " ++ ln

getGeneroPessoa :: Pessoa -> Genero
getGeneroPessoa (Pessoa _ _ gender) = gender

-- Desafio

data Nat = Zero
         | Suc Nat
            deriving Show

zero = Zero
um = Suc Zero
dois = Suc um
tres = Suc dois

nat2integer :: Nat -> Integer
nat2integer Zero = 0
nat2integer (Suc a) = (nat2integer a) + 1
 
integer2Nat :: Integer -> Nat
integer2Nat 0 = Zero
integer2Nat n = Suc (integer2Nat (n-1))

natAdd :: Nat -> Nat -> Nat
natAdd x y = integer2Nat ((nat2integer x) + (nat2integer y))

natSub :: Nat -> Nat -> Nat
natSub x y = integer2Nat ((nat2integer x) - (nat2integer y))

natMul :: Nat -> Nat -> Nat
natMul x y = integer2Nat ((nat2integer x) * (nat2integer y))