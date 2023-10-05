import sys
#sys.stdin = open("bj-solve\input.txt", 'r')

n = int(sys.stdin.readline().rstrip())
answer = 0
if n < 10:
    print(n)
    exit(0)
    
for i in range(len(str(n))-1):
    answer += 9 * (i + 1) * (10 ** i)
answer += (n + 1 - 10 ** (i + 1)) * (i + 2)
print(answer)