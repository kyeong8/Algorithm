import sys
#sys.stdin = open('test.txt', 'r')

N = int(sys.stdin.readline().rstrip())

arr = []
arr2 = []
for i in range(1, N+1):
    if N % i == 0:
        arr.append(i)

for j in range(1, len(arr)):
    flag = 0
    for k in range(2, arr[j]):
        if arr[j] % k == 0:
            flag += 1
    if flag == 0:
        arr2.append(arr[j])

m = 0
while N != 1:
    if N % arr2[m] == 0:
        N = N // arr2[m]
        print(arr2[m])
    else:
        m += 1
