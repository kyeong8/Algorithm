from collections import Counter
import sys

#sys.stdin = open('input.txt', 'r')
N = int(sys.stdin.readline().rstrip())
arr = list(map(int, sys.stdin.readline().split()))
count = Counter(arr)
result = [-1 for i in range(N)]
stack = [0]


for index, i in enumerate(arr):
    while stack and count[arr[stack[-1]]] < count[i]:
        result[stack.pop()] = i
    stack.append(index)

print(*result)