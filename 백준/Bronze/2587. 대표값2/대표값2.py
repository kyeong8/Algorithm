import sys
#sys.stdin = open('bj-solve\input.txt', 'r')

arr = []
for i in range(5):
    arr.append(int(sys.stdin.readline().rstrip()))

arr.sort()
print(int(sum(arr)/5))
print(arr[2])
