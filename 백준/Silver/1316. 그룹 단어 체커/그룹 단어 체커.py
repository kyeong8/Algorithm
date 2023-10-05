import sys
#sys.stdin = open('test.txt', 'r')

N = int(sys.stdin.readline().rstrip())
cnt = 0

for i in range(N):
    mem = []
    S = list(sys.stdin.readline().rstrip())
    for j in S:
        if j not in mem:
            mem.append(j)
        else:
            if mem[-1] != j:
                cnt = cnt - 1
                break
    cnt = cnt + 1

print(cnt)