isVoter :: Float -> String
isVoter age | age < 16 = "nao eleitor"
 | 18 <= age && age < 65 = "eleitor obrigatorio"
 | (16 <= age && age < 18) || age >= 65 = "eleitor facultativo"