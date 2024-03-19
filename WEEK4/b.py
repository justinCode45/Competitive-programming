
inp = input()
N, K = inp.split()
N = int(N)
K = int(K)

if 2**K >= N:
    print("Your wish is granted!")
else:
    print("You will become a flying monkey!")