import sys
input = sys.stdin.readline
lst = list(map(int, input().rstrip().split()))
print(*sorted(lst))