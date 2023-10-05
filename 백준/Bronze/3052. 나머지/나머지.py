import sys
#sys.stdin = open('test.txt', 'r')

arr = []
arr2 = [-1 for _ in range(10)]

flag = 0
count = 0

for _ in range(10):
    A = int(sys.stdin.readline().rstrip())
    A = A % 42
    arr.append(A)

for i in range(10):
    for j in range(10):
        if arr[i] == arr[j]:
            for k in range(10):
                if arr2[k] == arr[i]:
                    flag = flag + 1

        else:
            for k in range(10):
                if arr2[k] == arr[i]:
                    flag = flag + 1

        if flag == 0:
            arr2[i] = arr[i]

        flag = 0

for n in range(10):
    if arr2[n] >= 0:
        count = count + 1

print(count)
