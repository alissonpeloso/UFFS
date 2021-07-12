#Rode a aplicação em uma linguagem de programação capaz de executar N inserções  usando uma transação na tabela “Cliente”. A aplicação deve ser  capaz também de listar a tabela após as inserções.  Trate a exceção no caso  de uma inserção de uma chave já existente. 

import psycopg2
from tabulate import tabulate

def connect():
    return psycopg2.connect(database="homework2", user="teste", password = "123", host = "localhost", port = "5432")

def insert_customer():
    tuplas = int(input("Quantas tuplas você deseja inserir? "))
    conn = None
    try:
        conn = connect()
        cur = conn.cursor()
        for i in range(tuplas):
            print("\nInsira o valores da inserção", i+1)
            number = input("Insira o ID: ")
            cpf = input("Insira o CPF: ")
            name = input("Insira o nome: ")
            cur.execute("insert into cliente values ("+number+","+cpf+",'"+name+"')")
        conn.commit()
        cur.close()
    except psycopg2.errors.UniqueViolation as error:
        print("\n\tERRO: chave primária duplicada")
    except psycopg2.DatabaseError as error:
        print(type(error))
        print("Ops, foi detectado o seguinte erro: ",error)
    finally:
        if conn is not None:
            conn.close()

def select_customer():
    conn = None
    try:
        conn = connect()
        cur = conn.cursor()
        cur.execute("SELECT * FROM cliente ORDER BY numero asc")
        rows = cur.fetchall()
        if cur.rowcount > 0:
            header = ['Número', 'CPF', 'Nome']
            rows.insert(0, header)      
            print(tabulate(rows, headers='firstrow', tablefmt='fancy_grid'))
        print('\n',cur.rowcount,'registro(s) encontrado(s)')        
        cur.close()
    except (Exception, psycopg2.DatabaseError) as error:
        print("\tERRO:", error)
    finally:
        if conn is not None:
            conn.close()

def menu():
    key = 1
    while(key):
        print("\n\t### MENU ###")
        print("1) Inserir cliente na tabela clientes\n2) Ver tabela clientes\n3) Sair\n")
        key = int(input("Selecione a Opção desejada: "))

        if key == 1:
            insert_customer()
        elif key == 2:
            select_customer()
        elif key == 3:
            exit(1)
        else:
            print("ERRO: Opção inválida")

menu()