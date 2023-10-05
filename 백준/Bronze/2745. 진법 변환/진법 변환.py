import sys
#sys.stdin = open('input.txt', 'r')

N, B = map(str, sys.stdin.readline().split())

total = 0
if N != '0':
    for idx, i in enumerate(N[::-1]):
        if i.isdigit():
            total += int(B) ** idx * int(i)
        else:
            total += int(B) ** idx * (ord(i) - 65 + 10)
print(total)