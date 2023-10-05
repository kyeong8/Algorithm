import sys
#sys.stdin = open('input.txt', 'r')

arr = [1, 1, 2, 2, 2, 8]
mem = int(sys.stdin.readline().rstrip())
N = int(sys.stdin.readline().rstrip())
total = 0

for i in range(N):
    price, cnt = map(int, sys.stdin.readline().split())
    total += price * cnt

if total == mem:
    print('Yes')
else:
    print('No')