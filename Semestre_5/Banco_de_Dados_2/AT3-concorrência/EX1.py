#1- Qual o tempo de execução na inserção de 10000 tuplas com o autocommit True e False? Explique o que aconteceu. OBS: rodar 5 vezes e fazer a média e desvio padrão dos tempos de execução

import psycopg2
from tabulate import tabulate
import time
import numpy

def connect():
    return psycopg2.connect(database="homework2", user="teste", password = "123", host = "localhost", port = "5432")

def insert_customer(autocommit):
    tuplas = 10000
    conn = None
    try:
        if autocommit:
            conn = connect()
            conn.autocommit = True
            cur = conn.cursor()
            for i in range(tuplas):
                cur.execute("insert into cliente values ("+str(i)+","+str(i)+",'teste')")
            cur.close()
        else:
            conn = connect()
            cur = conn.cursor()
            for i in range(tuplas):
                cur.execute("insert into cliente values ("+str(i)+","+str(i)+",'teste')")
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

def truncate_customer():
    conn = None
    try:
        conn = connect()
        cur = conn.cursor()
        cur.execute("truncate table cliente")
        conn.commit()
        cur.close()
    except psycopg2.DatabaseError as error:
        print(error)
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

times = []

for i in range(5):
    truncate_customer()
    start = time.time()
    insert_customer(True)
    end = time.time()
    times.append(end-start)
    truncate_customer()

deviation = numpy.std(times)
avg = numpy.average(times)

print("*** Autocommit ON ***")
print(times)
print("Tempo Médio de execução:",avg)
print("Desvio Padrão de execução:",deviation)
print()

times = []

for i in range(5):
    truncate_customer()
    start = time.time()
    insert_customer(False)
    end = time.time()
    times.append(end-start)
    truncate_customer()

deviation = numpy.std(times)
avg = numpy.average(times)

print("*** Autocommit OFF ***")
print(times)
print("Tempo Médio de execução:",avg)
print("Desvio Padrão de execução:",deviation)