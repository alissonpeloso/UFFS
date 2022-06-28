grade :: Float -> Float -> Float -> String
grade a b c | x < 3 = "reprovado"
 | x < 7 = "exame especial"
 | x <= 10 = "aprovado"
 where
	x = (a + b + c) / 3