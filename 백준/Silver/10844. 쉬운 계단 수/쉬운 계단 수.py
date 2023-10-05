import sys
#sys.stdin = open('input.txt', 'r')

arr = [1 for i in range(10)]
arr[0] = 0
N = int(sys.stdin.readline().rstrip())

for _ in range(N-1):
    mem = arr[::]
    for idx, i in enumerate(mem):
        if i > 0 and idx == 0:
            arr[idx + 1] += i
        elif i > 0 and idx == 9:
            arr[idx - 1] += i
        elif i > 0:
            arr[idx + 1] += i
            arr[idx - 1] += i
        if i > 0:
            arr[idx] -= i

print(sum(arr) % 1000000000)