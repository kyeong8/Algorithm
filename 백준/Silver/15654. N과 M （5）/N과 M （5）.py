import sys
#sys.stdin = open("bj-solve\input.txt", 'r')

n, m = map(int, sys.stdin.readline().split())
num = list(map(int, sys.stdin.readline().split()))
num.sort()

def dfs(cnt, answer):
    if cnt == m:
        print(" ".join(map(str, answer)))
        return
    
    for i in num:
        if cnt == 0:
            dfs(cnt + 1, answer + [i])
        else:
            if i not in answer:
                dfs(cnt + 1, answer + [i])

dfs(0, [])