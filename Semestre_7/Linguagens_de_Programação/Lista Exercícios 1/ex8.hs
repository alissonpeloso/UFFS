isPalindromo :: String -> Bool
isPalindromo s | s == reverse(s) = True
 | otherwise = False