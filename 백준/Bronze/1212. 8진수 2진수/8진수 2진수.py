import sys
#sys.stdin = open('input.txt', 'r')

arr = list(map(int, sys.stdin.readline().rstrip()))
result = []
temp = 0

for i in arr:
    temp = i//4
    i = i - temp * 4
    if not result and temp == 0:
        pass
    else:
        result.append(str(temp))
    temp = i//2
    i = i - temp * 2
    if not result and temp == 0:
        pass
    else:
        result.append(str(temp))
    result.append(str(i))
    temp = 0

print(''.join(result))