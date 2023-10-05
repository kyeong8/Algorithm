import sys

#sys.stdin = open('input.txt', 'r')


def dfs(now, total):
    for i in range(now, N+1):
        if i + arr[i][0]-1 > N:
            continue
        pre_now = i
        pre_total = total
        now = i + arr[i][0]
        total += arr[i][1]
        dfs(now, total)
        now = pre_now
        total = pre_total

    answer.append(total)

    
answer = []
arr = [[]]
N = int(input().rstrip())
visited = [0 for _ in range(N+1)]

for _ in range(N):
    arr.append(list(map(int, input().split())))

dfs(1, 0)

print(max(answer))

