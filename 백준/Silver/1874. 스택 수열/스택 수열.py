import sys
#sys.stdin = open('input.txt', 'r')

n = int(sys.stdin.readline().rstrip())
arr = [i for i in range(1, n + 1)]
stack = []
stop = 0
result = []

for _ in range(n):
    num = int(sys.stdin.readline().rstrip())
    mem = stop
    if num > stop:
        for i in range(mem + 1, num + 1):
            stack.append(i)
            stop += 1
            result.append('+')
    if stack[-1] == num:
        stack.pop()
        result.append('-')

if result.count('+') == result.count('-'):
    for i in range(len(result)):
        print(result[i])
else:
    print('NO')