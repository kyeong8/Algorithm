import sys
#sys.stdin = open("bj-solve\input.txt", 'r')
arr = []

for i in range(9):
    arr.append(int(sys.stdin.readline().rstrip()))

for i in range(8):
    for j in range(i+1, 9):
        tmp = []
        for k in range(9):
            if k != i and k != j:
                tmp.append(arr[k])
        if sum(tmp) == 100:
            tmp.sort()
            for i in range(7):
                print(tmp[i])
            exit(0)