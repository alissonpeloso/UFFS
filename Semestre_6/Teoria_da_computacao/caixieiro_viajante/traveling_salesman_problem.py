import sys

def modifyBit(n, p, b):
	mask = 1 << p
	return(n & ~mask) | ((b << p) & mask)

def pd(u, todo, cache, dst):
	todo_bin = bin(todo)[2:]
	todo_bin = todo_bin[::-1]

	print(todo_bin)

	print(u, todo)

	if cache[u][todo-1] != -1:
		return cache[u][todo-1]
	if todo == 0:
		return dst[u][0]
	resp = sys.maxsize
	for v in range(0,len(todo_bin)):
		if(int(todo_bin[v]) == 1):
			c = dst[u][v] + pd(v, modifyBit(todo, v, 0), cache, dst)
			resp = min(resp, c)
	cache[u][todo-1] = resp
	return resp

def createMatrix(vector, rows, columns, default):
	for i in range(rows):
		newRow = []
		for j in range(columns):
			newRow.append(default)
		vector.append(newRow)

def main():
	n = 4
	todo = (1 << n+1) -1

	cache = []
	createMatrix(cache, n, todo, -1)

	dst = [
		[0, 3, 1, 9],
		[3, 0, 5, 7],
		[1, 5, 0, 11],
		[9, 7, 11, 0]
	]

	r = pd(0, todo, cache, dst)
	print(r)

main()