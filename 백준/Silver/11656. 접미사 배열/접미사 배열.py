import sys
#sys.stdin = open('input.txt', 'r')

arr = list(sys.stdin.readline().rstrip())
result = [''.join(arr)]

for i in range(len(arr) - 1):
    arr.pop(0)
    result.append(''.join(arr))

result.sort()

for i in range(len(result)):
    print(result[i])