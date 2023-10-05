import sys
#sys.stdin = open("bj-solve\input.txt", 'r')

n, m = map(int, sys.stdin.readline().split())

def dfs(cnt, answer):
    if cnt == m:
        print(" ".join(map(str, answer)))
        return
    
    for i in range(1, n+1):
        dfs(cnt + 1, answer + [i])

dfs(0, [])