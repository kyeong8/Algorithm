def combine(ans):
    if len(ans) == m:
        print(*ans)
    else:
        for i in range(1, n + 1):
            if len(ans) >= 1 and i <= ans[-1]:
                continue
            else:
                ans.append(i)
                combine(ans)
                ans.pop()


n, m = map(int, input().split())
combine([])