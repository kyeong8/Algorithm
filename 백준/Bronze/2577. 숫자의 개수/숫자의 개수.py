import sys
#sys.stdin = open('test.txt', 'r')

A = int(sys.stdin.readline().rstrip())
B = int(sys.stdin.readline().rstrip())
C = int(sys.stdin.readline().rstrip())

D = A*B*C
rest = 0
arr = [0 for _ in range(10)]
#arr = list(map(int, str(A*B*C)))

#for i in range(10):
#    print(arr.count(i))

while D != 0:
    rest = D % 10
    arr[rest] = arr[rest] + 1
    D = D // 10

for i in range(10):
    print(arr[i])


