import sys
#sys.stdin = open('input.txt', 'r')

N, M = map(int, sys.stdin.readline().split())
a = []
b = []

for i in range(N):
    a.append(sys.stdin.readline().rstrip())

for i in range(M):
    b.append(sys.stdin.readline().rstrip())

result = list(set(a) & set(b))
print(len(result))
result.sort()
for i in range(len(result)):
    print(result[i])