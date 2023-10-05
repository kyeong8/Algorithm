import sys
#sys.stdin = open('input.txt', 'r')

A, B = map(int, sys.stdin.readline().split())
m = int(sys.stdin.readline().rstrip())
arr = list(map(int, sys.stdin.readline().split()))
result = []
quotient, remain = 0, 0
total = 0
for idx, i in enumerate(arr[::-1]):
    total += A ** idx * i

quotient = total
while quotient != 0:
    result.append(quotient % B)
    quotient = quotient // B

print(*result[::-1])
