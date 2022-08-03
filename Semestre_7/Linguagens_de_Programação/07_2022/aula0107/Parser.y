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
	and		{ TokenAnd }
	or		{ TokenOr }
	True	{ TokenTrue }
	False	{ TokenFalse }
	lam		{ TokenLambda }
	let 	{ TokenLet }

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
        | Exp 'and' Exp   { And $1 $3 }
        | Exp 'or' Exp   { Or $1 $3 }
		| true		{ BTrue }
		| false		{ BFalse }
		| lam var Ty Exp	{ Lam $2 $3 $4}
		| Exp Exp          	{ App $1 $2 }
		| var 			{ Var $1 }
		| let var Exp 	{ Let $2 $3 }

{

data Ty = TBool
	| TNum
	| TFun Ty Ty
	deriving (Show, Eq)

data Expr = Num Int
          | Add Expr Expr
          | Minus Expr Expr
          | Times Expr Expr
          | Paren Expr
          | If Expr Expr Expr
		  | And Expr Expr
		  | Or Expr Expr
		  | BTrue
		  | BFalse
		  | Lam String Ty Expr
		  | App Expr Expr
		  | Var String
		  | Let String Expr
          deriving Show

parseError :: [Token] -> a
parseError _ = error "Syntax Error!"

}