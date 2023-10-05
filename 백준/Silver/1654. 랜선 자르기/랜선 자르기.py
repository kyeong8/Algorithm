import sys

#sys.stdin = open('input.txt', 'r')
K, N = map(int, sys.stdin.readline().split())
arr = []
total = 0

for i in range(K):
    temp = int(sys.stdin.readline().rstrip())
    total += temp
    arr.append(temp)

Max = max(arr)
cnt = 1
total = 0

while True:
    res = Max // cnt
    if res <= 0:
        break
    for i in arr:
        total += (i // res)
        if total >= N:
            break
    if total >= N:
        break
    cnt += 1
    total = 0

if (cnt - 1) <= 0:
    right = 0
else:
    right = Max // (cnt - 1)
left = res
mid = (left + right) // 2
mem = []
total = 0

while left <= right:
    if mid <= 0:
        break
    for i in arr:
        total += (i // mid)
        if total >= N:
            break
    if total >= N:
        mem.append(mid)
        left = mid + 1
        mid = (left + right) // 2
    else:
        right = mid - 1
        mid = (left + right) // 2
    total = 0

if not mem:
    print(res)
else:
    print(max(mem))
