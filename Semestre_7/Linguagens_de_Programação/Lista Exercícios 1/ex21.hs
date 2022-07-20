and' :: Bool -> Bool -> Bool
and' True True = True
and' False _ = False
and' _ False = False

or' :: Bool -> Bool -> Bool
or' True _ = True
or' _ True = True
or' False False = False