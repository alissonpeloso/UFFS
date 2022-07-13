module Main where

import Lexer
import Parser

-- cat teste.mylang | runghc Main.hs

main :: IO ()
main = getContents >>= print . parser . lexer