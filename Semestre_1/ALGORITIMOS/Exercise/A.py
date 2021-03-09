def transtr(stri,x):
    v=''
    for i in range(len(stri)):
        if stri[i] == x:
            v+='*'
        else:
            v+=stri[i]
    return v

print(transtr('aaaaaaaa','a'))
