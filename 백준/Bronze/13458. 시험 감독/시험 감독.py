import sys

#sys.stdin = open('input.txt', 'r')

N = int(input().rstrip())
arr = list(map(int, input().split()))
A, B = map(int, input().split())

answer = N
for i in range(N):
    arr[i] -= A
    if arr[i] > 0:
        if (arr[i] / B) > arr[i] // B:
            answer += (arr[i] // B) + 1
        else:
            answer += arr[i] // B

print(answer)