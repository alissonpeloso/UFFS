module Main where

import Lexer
import Parser
import Semantic

-- cat teste.mylang | runghc Main.hs

main :: IO ()
main = getContents >>= print . step . parser . lexer