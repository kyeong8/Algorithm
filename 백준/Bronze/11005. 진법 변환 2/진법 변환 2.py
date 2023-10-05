import sys
#sys.stdin = open('input.txt', 'r')


N, B = map(int, sys.stdin.readline().split())
quotient = N
remain = []

while quotient != 0:
    remain.append(quotient % B)
    quotient = quotient // B

for i in remain[::-1]:
    if i >= 10:
        print(chr(65 + i - 10), end='')
    else:
        print(i, end='')