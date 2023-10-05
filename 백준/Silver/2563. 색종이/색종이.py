import sys
#sys.stdin = open('input.txt', 'r')

n = int(sys.stdin.readline().rstrip())
m = []
for i in range(n):
    m.append(list(map(int, sys.stdin.readline().split())))

arr = [[0 for _ in range(101)] for _ in range(101)]
for i, j in m:
    for s in range(i, i+10):
        for t in range(j, j+10):
            if arr[s][t] == 0:
                arr[s][t] = 1
            elif arr[s][t] == 1:
                pass
result = 0
for i in range(101):
    result += sum(arr[i])
print(result)