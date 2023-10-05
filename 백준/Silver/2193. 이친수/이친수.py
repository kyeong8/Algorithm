import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
arr = [0, 1]

for _ in range(N-1):
    if N == 1:
        break
    else:
        a = arr[0]
        b = arr[1]
        arr[1] += a
        arr[0] += b
        arr[1] -= b

print(sum(arr))