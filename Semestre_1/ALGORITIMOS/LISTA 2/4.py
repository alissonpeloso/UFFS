i,j,k = map(int, input().split())
if i > j or k < j:
    print('{} {} {}'.format(i,j,k))
else:
    print('{} {} {}'.format(i,k,j))
