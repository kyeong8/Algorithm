import sys
sys.setrecursionlimit(10**6)
#sys.stdin = open('test.txt', 'r')

def recursive(N):
    if N == 3:
        return ['***', '* *', '***']

    arr = recursive(N//3)
    arr2 = []

    for i in arr:
        arr2.append(i*3)
    for i in arr:
        arr2.append(i + ' ' * (N//3) + i)
    for i in arr:
        arr2.append(i*3)

    return arr2

num = int(sys.stdin.readline().rstrip())
print('\n'.join(recursive(num)))