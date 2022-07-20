imc :: Float -> String -> Float
imc h "masculino" = 72.7 * h - 58
imc h "feminino" = 62.1 * h - 44.7
