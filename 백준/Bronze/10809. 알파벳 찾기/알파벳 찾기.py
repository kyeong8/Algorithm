import sys
#sys.stdin = open('test.txt', 'r')

arr = list(sys.stdin.readline().rstrip())
flag = -1
for i in range(ord('a'), ord('z')+1):
    for j in range(len(arr)):
        if arr[j] == chr(i):
            flag = j
            break

    if flag >= 0:
        print(flag, end=' ')
    else:
        print(-1, end=' ')
    flag = -1


