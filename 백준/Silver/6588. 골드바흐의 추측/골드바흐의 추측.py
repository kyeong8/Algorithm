import sys
#sys.stdin = open('input.txt', 'r')

x = 1000000
arr = [False, False] + [True] * (x-1)

for i in range(2, int(x**0.5 + 1)):
    for j in range(i+i, x+1, i):
        if arr:
            arr[j] = False

N = int(sys.stdin.readline().rstrip())

while N != 0:
    for i in range(2, 1000001):
        if arr[i] and arr[N-i]:
            print('{} = {} + {}'.format(N, i, N-i))
            break
    else:
        print("Goldbach's conjecture is wrong.")
    N = int(sys.stdin.readline().rstrip())