import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
d = []
for i in range(N):
    age, name = sys.stdin.readline().split()
    d.append([i, int(age), name])

d.sort(key=lambda x:(x[1], x[0]))

for i in range(len(d)):
    print(d[i][1], d[i][2])
