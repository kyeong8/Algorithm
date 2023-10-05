import sys
#sys.stdin = open('test.txt', 'r')

arr = []
num = int(sys.stdin.readline().rstrip())

for i in range(num):
    arr.append(int(sys.stdin.readline().rstrip()))
arr.sort()
for i in range(num):
    print(arr[i])
