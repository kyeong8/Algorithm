import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
arr = []

for i in range(N):
    arr.append(list(map(int, sys.stdin.readline().split())))

total = 0
for j in range(1, N - 1):
    a = [arr[0][0] - arr[j][0], arr[0][1] - arr[j][1]]
    b = [arr[0][0] - arr[j + 1][0], arr[0][1] - arr[j + 1][1]]
    total += 0.5 * (a[0] * b[1] - a[1] * b[0])
print(abs(total))