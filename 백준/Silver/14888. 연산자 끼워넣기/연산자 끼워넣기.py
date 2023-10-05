import sys
import copy
#sys.stdin = open("bj-solve\input.txt", 'r')
input = sys.stdin.readline

def dfs(depth, value):
    if depth == n-1:
        result.append(value)
        return

    for idx, i in enumerate(op):
        if not visited[idx]:                
            if i == '+':
                temp = value + num[depth+1] 
            elif i == '-':
                temp = value - num[depth+1] 
            elif i == '*':
                temp = value * num[depth+1] 
            else:
                temp = int(value / num[depth+1])

            visited[idx] = 1   
            dfs(depth+1, temp)
            visited[idx] = 0





n = int(input().rstrip())
num = list(map(int, input().split()))
temp = list(map(int, input().split()))
op = []
visited = [0 for _ in range(n-1)]

for idx, i in enumerate(['+', '-', '*', '/']):
    for j in range(temp[idx]):
        op.append(i)

result = []

dfs(0, num[0])

print(max(result), min(result))