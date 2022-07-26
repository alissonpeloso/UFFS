module Lambda where

import Data.List

data Expr   = BTrue
            | BFalse
            | Var String
            | Lam String Ty Expr
            | App Expr Expr
            deriving Show

data Ty = TBool
        | TFun Ty Ty
        deriving (Show, Eq)

type Ctx = [(String, Ty)]

subst :: String -> Expr -> Expr -> Expr
subst x n b@(Var v) =   if v == x then
                            n
                        else
                            b
subst x n (Lam v t b) = Lam v t (subst x n b)
subst x n (App e1 e2) = App (subst x n e1) (subst x n e2)
subst x n e = e

isValue :: Expr -> Bool
isValue BTrue = True
isValue BFalse = True
isValue (Lam _ _ _) = True
isValue _ = False

eval :: Expr -> Expr
eval (App e1@(Lam x _ b) e2)  | isValue e2 = subst x e2 b
                            | otherwise = App e1 (eval e2)
eval (App e1 e2) = App (eval e1) e2
eval e = e

eval' :: Expr -> Expr
eval' e | isValue e = e
        | otherwise = eval' (eval e)

typeof :: Ctx -> Expr -> Maybe Ty
typeof ctx BTrue = Just TBool
typeof ctx BFalse = Just TBool
typeof ctx (Var v) = lookup v ctx
typeof ctx (Lam v t1 b) = let Just t2 = typeof ((v,t1):ctx) b
                            in Just (TFun t1 t2)
typeof ctx (App e1 e2) = case (typeof ctx e1, typeof ctx e2) of
                            (Just (TFun t11 t12) , Just t2) -> 	if (t11 == t2) then
                                                                    Just t12
                                                                else
                                                                    Nothing
                            _                               -> Nothing

----------------------------

-- true :: Expr
-- true = Lam "a" (Lam "b" (Var "a"))

-- false :: Expr
-- false  = Lam "c" (Lam "d" (Var "d"))

-- if' :: Expr
-- if' = Lam "p" (Lam "x" (Lam "y" (App (App (Var "p") (Var "x")) (Var "y"))))

-- eval' (App (App (App if' false) (Lam "h" (Var "h"))) (Lam "g" (Var"g")))