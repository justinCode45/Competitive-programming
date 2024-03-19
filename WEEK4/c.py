n = input()
n = int(n)

a = []
b = []
c = 0
d = 0
fx = [[0 for _ in range(0,100)] for _ in range(0,100)]


def dp(x,y):
    if x <= 0 or y <= 0:
        return d
    if fx[x][y] != 0:
        return fx[x][y]

    for i in range(len(a)):
        fx[x][y] += dp(x-a[i],y-b[i])

    fx[x][y] +=c 
    return fx[x][y]    


for _ in range(n):
    fx = [[0 for _ in range(0,100)] for _ in range(0,100)]
    a = []
    b = []
    inp = input()
    inp = inp.split()
    inp = [int(x) for x in inp]
    for i in range(len(inp)):
        if i % 2 == 0:
            a.append(inp[i])
        else:
            b.append(inp[i])
    c = a.pop()
    d = b.pop()
    inp = input()
    inp = inp.split()
    inp = [int(x) for x in inp]
    inp = [(inp[i], inp[i+1]) for i in range(0, len(inp), 2)]
    for i in inp:
        print(dp(i[0],i[1]))
    print()


