import sys
#sys.stdin = open('input.txt', 'r')

def GCD(a, b):
    while b != 0:
        a, b = b, a%b
    return a


n = int(sys.stdin.readline().rstrip())

for i in range(n):
    arr = list(map(int, sys.stdin.readline().split()))
    total = 0
    for j in range(1, len(arr) - 1):
        for k in range(j+1, len(arr)):
            total += GCD(arr[j], arr[k])

    print(total)