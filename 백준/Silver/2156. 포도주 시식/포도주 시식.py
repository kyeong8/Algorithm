import sys
#sys.stdin = open('bj-solve\input.txt', 'r')

arr = [0]
n = int(sys.stdin.readline().rstrip())
for i in range(n):
    arr.append(int(sys.stdin.readline().rstrip()))
    
result = [0 for _ in range(10001)]

if n == 1:
    print(arr[1])
    exit()
elif n == 2:
    print(arr[1]+arr[2])
    exit()

result[1] = arr[1]
result[2] = arr[1] + arr[2]

for i in range(3, n+1):
    result[i] = max(result[i-1], arr[i] + result[i-2], arr[i] + arr[i-1] + result[i-3])
print(result[n])