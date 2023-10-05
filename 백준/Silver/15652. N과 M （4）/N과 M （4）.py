import sys
#sys.stdin = open("bj-solve\input.txt", 'r')

n, m = map(int, sys.stdin.readline().split())

def dfs(cnt, answer):
    if cnt == m:
        print(" ".join(map(str, answer)))
        return
    
    for i in range(1, n+1):
        if cnt == 0:
            dfs(cnt + 1, answer + [i])
        else:
            if answer[-1] <= i:
                dfs(cnt + 1, answer + [i])

dfs(0, [])