import sys
#sys.stdin = open('input.txt', 'r')

def count_two(num):
    cnt = 0
    while num != 0:
        cnt += num//2
        num = num//2
    return cnt


def count_five(num):
    cnt = 0
    while num != 0:
        cnt += num//5
        num = num//5
    return cnt

n, m = map(int, sys.stdin.readline().split())

print(min(count_two(n) - count_two(n-m) - count_two(m), count_five(n) - count_five(n-m) - count_five(m)))