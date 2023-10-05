import sys

#sys.stdin = open('input.txt', 'r')
N = int(sys.stdin.readline().rstrip())
arr = list(map(int, sys.stdin.readline().split()))
result = [-1 for i in range(N)]
stack = []

for index, i in enumerate(arr):
    while stack and (stack[-1][1] < i):
        idx, value = stack.pop()
        result[idx] = i
    stack.append([index, i])

print(*result)