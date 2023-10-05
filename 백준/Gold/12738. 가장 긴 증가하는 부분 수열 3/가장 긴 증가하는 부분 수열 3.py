import sys

def binary_search(arr, num):
    low = 0
    high = len(arr) - 1

    while low  <= high:
        mid = (low + high) // 2
        if num == arr[mid]:
            return mid
        elif num < arr[mid]:
            high = mid - 1
        else:
            low = mid + 1
    return low

#sys.stdin = open('bj-solve\input.txt', 'r')

n = int(sys.stdin.readline().rstrip())
a = list(map(int, sys.stdin.readline().split()))

dp = [a[0]]

for i in range(1, n):
    if dp[-1] < a[i]:
        dp.append(a[i])
    else:
        index = binary_search(dp, a[i])
        dp[index] = a[i]

print(len(dp))