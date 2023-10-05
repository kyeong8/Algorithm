import sys
#sys.stdin = open('input.txt', 'r')

def GCD(a, b):
    while b != 0:
        a, b = b, a%b
    return a


temp = 0
flag = 0
N, S = map(int, sys.stdin.readline().split())
if N == 1:
    A = int(sys.stdin.readline().rstrip())
    flag = 1
    print(abs(A-S))
else:
    arr = list(map(int, sys.stdin.readline().split()))
    for i in arr:
        diff = abs(i-S)
        if diff == 2:
            temp = 2
        else:
            for j in range(2, int(diff**0.5 + 1)):
                if diff % j == 0:
                    if temp == 0:
                        temp = diff
                    else:
                        temp = GCD(diff, temp)
                    break
            else:
                print(1)
                flag = 1
                break
if flag != 1:
    print(temp)
