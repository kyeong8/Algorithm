import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
pack = [0]
pack.extend(list(map(int, sys.stdin.readline().split())))

for i in range(1, len(pack)):
    for j in range(1, i):
        pack[i] = min(pack[i], pack[i-j] + pack[j])

print(pack[N])