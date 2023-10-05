import sys
#sys.stdin = open('bj14235.txt', 'r')

N = int(sys.stdin.readline().rstrip())
M = N
temp = -1
count = 0

while True:
    if temp == M:
        break

    if N < 10:
        temp = N * 10 + N
    else:
        temp = (N % 10) * 10 + (N // 10 + N % 10) % 10

    N = temp
    count = count + 1

print(count)
