import sys

#sys.stdin = open("bj-solve\input.txt", 'r')

e, s, m = map(int, sys.stdin.readline().split())
i = 1

while True:
    if (i-e) % 15 == 0 and (i-s) % 28 == 0 and (i-m) % 19 == 0:
        print(i)
        break
    i += 1