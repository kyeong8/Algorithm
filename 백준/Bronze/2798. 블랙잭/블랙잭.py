import sys
#sys.stdin = open('input.txt', 'r')

N, M = map(int, sys.stdin.readline().split())
sum = 0

arr = list(map(int, sys.stdin.readline().split()))
brute = []

for m in range(N-2):
    for n in range(1+m, N-1):
        for k in range(1+n, N):
            brute.append(arr[m]+arr[n]+arr[k])

brute.sort()


left = 0
right = len(brute)
index = (left+right)//2
mem = index
flag = 0
while 0 <= index <= len(brute) and left < right:
    if brute[index] > M:
        mem = index
        right = index - 1
        index = (index+left)//2
    elif brute[index] < M:
        mem = index
        left = index + 1
        index = (index+right)//2
    else:
        flag = 1
        break

if flag == 0 and brute[mem] > M:
    print(brute[mem-1])
elif flag == 0 and brute[mem] < M:
    print(brute[mem])
elif flag == 1:
    print(brute[index])
