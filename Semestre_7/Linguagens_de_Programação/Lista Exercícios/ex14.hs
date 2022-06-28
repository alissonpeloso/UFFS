ultimo :: [a] -> a
ultimo (x:[]) = x
ultimo (x:xs) = ultimo(xs)