module Lexer where

data Ty = TBool
		| TNum
        | TFun Ty Ty
        deriving (Show, Eq)

data Expr   = BTrue
            | BFalse
			| Num Int
            | Var String
            | Lam String Ty Expr
            | App Expr Expr
			| Add Expr Expr
            deriving Show

-- Implementar função lexer abaixo