import sys
#sys.stdin = open('input.txt', 'r')

T = int(sys.stdin.readline().rstrip())

for i in range(T):
    arr = list(sys.stdin.readline().rstrip())
    cnt = 0
    flag = 0
    for j in arr:
        if j == '(':
            cnt += 1
        else:
            cnt -= 1
        if cnt < 0:
            print('NO')
            flag = 1
            break
    if cnt != 0 and flag == 0:
        print('NO')
    elif cnt == 0 and flag == 0:
        print('YES')