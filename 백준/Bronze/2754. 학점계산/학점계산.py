import sys
#sys.stdin = open('input.txt', 'r')


N = list(sys.stdin.readline().rstrip())

if len(N) == 1:
    print('{:.1f}'.format(70-ord(N[0])))
    exit(0)
if N[1] == '+':
    print('{:.1f}'.format(69-ord(N[0]) + 0.3))
elif N[1] == '0':
    print('{:.1f}'.format(69-ord(N[0])))
elif N[1] == '-':
    print('{:.1f}'.format(69-ord(N[0]) - 0.3))
