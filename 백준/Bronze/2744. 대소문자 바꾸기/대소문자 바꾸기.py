import sys
#sys.stdin = open('input.txt', 'r')


N = list(sys.stdin.readline().rstrip())

for i in N:
    if i.islower():
        print(i.upper(), end='')
    else:
        print(i.lower(), end='')