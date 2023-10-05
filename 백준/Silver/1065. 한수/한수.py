import sys
#sys.stdin = open('test.txt', 'r')

def d(a: int):
    if a // 10 == 0:
        return True
    arr = []
    m = a
    while m != 0:
        n = m % 10
        m = m // 10
        arr.append(n)

    diff = arr[0] - arr[1]
    for i in range(len(arr)-1):
        if (arr[i] - arr[i+1]) != diff:
            return False

    return True

N = int(sys.stdin.readline().rstrip())

cnt = 0

for i in range(1, N+1):
    if d(i):
        cnt = cnt + 1
print(cnt)


