import sys
#sys.stdin = open('input.txt', 'r')

T = int(sys.stdin.readline().rstrip())

for i in range(T):
    N = int(sys.stdin.readline().rstrip())
    arr = []
    for j in range(2):
        arr.append(list(map(int, sys.stdin.readline().split())))
        arr[j] = [0] + arr[j]

    dp = [[0]*(N+1) for _ in range(3)]
    dp[0][1] = arr[0][1]
    dp[1][1] = arr[1][1]

    for k in range(2, N+1):
        dp[2][k-1] = max(dp[0][k-2], dp[1][k-2])
        dp[0][k] = max(dp[2][k-1] + arr[0][k], arr[0][k] + dp[1][k - 1])
        dp[1][k] = max(dp[2][k-1] + arr[1][k], arr[1][k] + dp[0][k - 1])

    print(max(dp[0][-1], dp[1][-1]))
