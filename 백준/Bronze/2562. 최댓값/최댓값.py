import sys
#sys.stdin = open('bj14235.txt', 'r')

arr = []
for _ in range(9):
    arr.append(int(sys.stdin.readline().rstrip()))

print(max(arr))
print(arr.index(max(arr))+1)