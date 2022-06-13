-- Desafio
-- Alisson Luan de Lima Peloso

data Nat = Zero
         | Suc Nat
            deriving Show

zero :: Nat
zero = Zero

um :: Nat
um = Suc Zero

dois :: Nat
dois = Suc um

tres :: Nat
tres = Suc dois

nat2integer :: Nat -> Integer
nat2integer Zero = 0
nat2integer (Suc a) = nat2integer a + 1

integer2Nat :: Integer -> Nat
integer2Nat 0 = Zero
integer2Nat n = Suc (integer2Nat (n-1))

natAdd :: Nat -> Nat -> Nat
natAdd x Zero = x
natAdd x (Suc y) = natAdd (Suc x) y

natSub :: Nat -> Nat -> Nat
natSub x Zero = x
natSub Zero _ = Zero
natSub (Suc x) (Suc y) = natSub x y

natMul :: Nat -> Nat -> Nat
natMul x Zero = Zero
natMul x (Suc y) = natAdd x (natMul x y)