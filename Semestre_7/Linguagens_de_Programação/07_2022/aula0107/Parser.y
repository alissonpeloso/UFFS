{
module Parser where

import Lexer
}

%name parser
%tokentype { Token }
%error { parseError }

%token
    num     { TokenNum $$ }
    '+'     { TokenPlus }
    '-'     { TokenMinus }
    '*'     { TokenTimes }
    '('     { TokenLParen }
    ')'     { ToknenRParen }
    if      { TokenIf }
    then    { TokenThen }
    else    { TokenElse }

%nonassoc if then else
%left '+' '-'
%left '*'

%%

Exp     : num           { Num $1 }
        | Exp '+' Exp   { Add $1 $3 }
        | Exp '-' Exp   { Minus $1 $3 }
        | Exp '*' Exp   { Times $1 $3  }
        | '(' Exp ')'   { Paren $2 }
        | if Exp then Exp else Exp { If $2 $4 $6 } 

{

data Expr = Num Int
          | Add Expr Expr
          | Minus Expr Expr
          | Times Expr Expr
          | Paren Expr
          | If Expr Expr Expr
          deriving Show

parseError :: [Token] -> a
parseError _ = error "Syntax Error!"

}