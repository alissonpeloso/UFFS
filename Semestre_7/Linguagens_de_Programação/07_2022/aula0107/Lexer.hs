module Lexer where

import Data.Char

data Token = TokenNum Int
            | TokenPlus
            | TokenTimes
            | TokenLParen
            | ToknenRParen
            | TokenMinus
            | TokenIf
            | TokenThen
            | TokenElse
            deriving Show 

-- Função que recebe o código-fonte e retorna uma lista de tokens

lexer :: String -> [Token]
lexer [] = []
lexer ('+':cs) = TokenPlus : lexer cs
lexer ('-':cs) = TokenMinus : lexer cs
lexer ('*':cs) = TokenTimes : lexer cs
lexer ('(':cs) = TokenLParen : lexer cs
lexer (')':cs) = ToknenRParen : lexer cs
lexer (c:cs)
    | isSpace c = lexer cs
    | isDigit c = lexNum (c:cs)
    | isAlpha c = lexKW (c:cs)
lexer _ = error "Lexical error: caracter inválido"


lexNum :: [Char] -> [Token]
lexNum cs = case span isDigit cs of
                    (num, rest) -> TokenNum (read num) : lexer rest

lexKW :: [Char] -> [Token]
lexKW cs = case span isAlpha cs of
                    ("if", rest) -> TokenIf : lexer rest
                    ("then", rest) -> TokenThen : lexer rest
                    ("else", rest) -> TokenElse : lexer rest
                    _ -> error "Lexical error: palavra-chave inválida"