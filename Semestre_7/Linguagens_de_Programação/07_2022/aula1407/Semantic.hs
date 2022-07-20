--- Avaliação Semântica
module Semantic where

import Parser

-- data Expr = BTrue
--           | BFalse
--           | Num Int
--           | Add Expr Expr
--           | And Expr Expr
--           | If Expr Expr Expr
--           deriving Show

step :: Expr -> Maybe Expr
step (Add (Num n1) (Num n2)) = Just (Num (n1 + n2))
step (Add e1@(Num n1) e2) = case step e2 of 
                            Just e2' -> Just(Add e1 e2')
                            _ -> Nothing
step (Add e1 e2) = case step e1 of 
                    Just e1' -> Just(Add e1' e2)
                    _ -> Nothing
step (And BFalse _) = Just BFalse
step (And BTrue e2) = Just e2
step (And e1 e2) = case step e1 of
                    Just e1' -> Just(And e1' e2)
                    _ -> Nothing
step (If BTrue e2 e3) = Just e2
step (If BFalse e2 e3) = Just e3
step (If e1 e2 e3) = case step e1 of
                        Just e1' -> Just(If e1' e2 e3)
                        _ -> Nothing
step e = Just e
