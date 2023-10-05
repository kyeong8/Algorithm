import sys
#sys.stdin = open('test.txt', 'r')

N = int(sys.stdin.readline().rstrip())

for _ in range(N):
    A, B = sys.stdin.readline().split()
    arr = [int(A)*j for j in B]
    print(''.join(arr))

