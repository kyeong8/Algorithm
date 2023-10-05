import sys
#sys.stdin = open('test.txt', 'r')

N = int(sys.stdin.readline().rstrip())

if N >= 8:
    if N % 5 == 0:
        print(N//5)
    elif N % 3 == 0:
        if N // 3 > 5:
            print(int(((N/3)//5) * 3 + (N/3)%5))
        else:
            print(N//3)
    else:
        i = N // 5
        k = N
        while True:
            N = k - 5 * i
            if (N % 3) != 0:
                i -= 1
            else:
                print(i + N//3)
                break

else:
    if N % 5 == 0:
        print(N//5)
    elif N % 3 == 0:
        print(N//3)
    else:
        print('-1')
