import sys
#sys.stdin = open("bj-solve\input.txt", 'r')
target = int(sys.stdin.readline().rstrip())
n = int(sys.stdin.readline().rstrip())
btn = list(map(int, sys.stdin.readline().split()))
min_cnt = abs(target - 100)

for i in range(1000001):
    i = str(i)
    for j in range(len(i)):
        if int(i[j]) in btn:
            break
        elif j == len(i) - 1:
            min_cnt = min(min_cnt, abs(int(i) - target) + len(i))
        
print(min_cnt)