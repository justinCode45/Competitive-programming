import array
n = input()
n = int(n)

a = []
b = []
c = 0
d = 0
fx = array.array(0, [])



def dp(x,y):
    if x <= 0 or y <= 0:
        return d
    


for _ in range(n):
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
    for i in range(len(inp)):
        if c <= inp[i][0] and d >= inp[i][1]:
            print("Yes")
        else:
            print("No")