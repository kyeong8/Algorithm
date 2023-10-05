import sys
#sys.stdin = open('test.txt', 'r')

N = int(sys.stdin.readline().rstrip())
i = 1
total = 1
while N > total:
    i = i + 1
    total = total + i

num = 1

if i % 2 == 0:
    index = i // 2
    for j in range(1, index+1):
        num = num + 4 * (j - 1) + 1
    print('{}/{}'.format(N-num+1, i-(N-num)))

else:
    index = i // 2
    for j in range(1, index+1):
        num = num + 4 * j + 1
    print('{}/{}'.format(num - N + 1, i - (num - N)))
