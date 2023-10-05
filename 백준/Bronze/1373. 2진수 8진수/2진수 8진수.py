import sys
#sys.stdin = open('input.txt', 'r')

arr = list(sys.stdin.readline().rstrip())
result = []
temp = 0
for index, i in enumerate(arr[::-1]):
    index = index % 3
    temp += 2 ** index * int(i)
    if index == 2:
        result.append(str(temp))
        temp = 0

if temp != 0:
    result.append(str(temp))

if result:
    print(''.join(result[::-1]))
else:
    print(0)