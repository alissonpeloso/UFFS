a, b, c = map (int, input().split())
if abs(b-c) < a < b+c and abs(a-c) < b < a+c and abs(a-b) < c < a + b:
    print('É um triầngulo')
else:
    print('Não é um triầngulo')
