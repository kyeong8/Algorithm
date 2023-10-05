import sys
#sys.stdin = open('input.txt', 'r')

arr = sys.stdin.readline().rstrip()
result = []

for i in range(len(arr)):
    for j in range(len(arr)):
        result.append(arr[j:j + i + 1])

print(len(set(result)))