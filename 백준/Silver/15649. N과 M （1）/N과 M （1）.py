def combine(ans):
    if len(ans) == m:
        print(*ans)
    else:
        for i in range(1, n + 1):
            if i not in ans:
                ans.append(i)
                combine(ans)
                ans.pop()


n, m = map(int, input().split())
combine([])