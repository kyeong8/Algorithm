import sys
#sys.stdin = open('test.txt', 'r')

T = int(sys.stdin.readline().rstrip())

for _ in range(T):
    H, W, N = map(int, sys.stdin.readline().split())
    YY = N % H
    XX = N // H

    if YY == 0:
        if XX < 10:
            print(str(H) + '0' + str(XX))
        else:
            print(str(H) + str(XX))
    else:
        if XX < 9:
            print(str(YY) + '0' + str(XX + 1))
        else:
            print(str(YY) + str(XX + 1))
