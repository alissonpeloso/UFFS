module Aula0306 where

data Cliente = OrgGov String
             | Empresa String Integer String String
             | Individuo Pessoa Bool
             deriving Show

data Pessoa = Pessoa String String Genero
            deriving Show

data Genero = Masculino | Feminino | Outro
            deriving Show

nomeCliente :: Cliente -> String
nomeCliente cliente = case cliente of 
                    OrgGov nome -> nome
                    Empresa nome id resp cargo -> nome
                    Individuo pessoa ads ->
                        case pessoa of
                            Pessoa pNome sNome g -> pNome ++ " " ++ sNome

nomeEmpresa' :: Cliente -> Maybe String
nomeEmpresa' cliente = case cliente of 
                        Empresa nome _ _ _ -> Just nome
                        _ -> Nothing

nomeCliente'' :: Cliente -> String
nomeCliente'' (OrgGov nome) = nome
nomeCliente'' (Empresa nome _ _ _) = nome
nomeCliente'' (Individuo (Pessoa pn sn _) _) = pn ++ " " ++ sn