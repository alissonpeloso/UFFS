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
    if      { TokenIf }
    then    { TokenThen }
    else    { TokenElse }
    and     { TokenAnd }
    True    { TokenTrue }
    False   { TokenFalse }

%nonassoc if then else
%left '+'

%%

Exp     : num           { Num $1 }
        | True          { BTrue }
        | False          { BFalse }
        | Exp '+' Exp   { Add $1 $3 }
        | Exp and Exp   { And $1 $3  }
        | if Exp then Exp else Exp { If $2 $4 $6 } 

{

data Expr = Num Int
          | Add Expr Expr
          | If Expr Expr Expr
          | And Expr Expr
          | BTrue 
          | BFalse
          deriving Show

parseError :: [Token] -> a
parseError _ = error "Syntax Error!"

}