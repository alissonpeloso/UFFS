module TypeChecker where

import Semantic

data Ty = TNum
        | TBool
        deriving (Eq,Show)

typeof :: Expr -> Maybe Ty
typeof (Num _) = Just TNum
typeof BTrue = Just TBool
typeof BFalse = Just TBool
typeof (Add e1 e2) = case typeof e1 of 
                        Just TNum -> case typeof e2 of
                                        Just TNum -> Just TNum
                                        _ -> Nothing
                        _ -> Nothing
typeof (And e1 e2) = case (typeof e1, typeof e2) of
                        (Just TBool, Just TBool) -> Just TBool
                        _ -> Nothing
typeof (If e1 e2 e3) = case typeof e1 of
                        Just TBool -> case (typeof e2, typeof e3) of
                                        (Just t1, Just t2) -> if t1 == t2 then
                                                                Just t1
                                                              else
                                                                Nothing
                                        _ -> Nothing
                        _ -> Nothing



