import sys
#sys.stdin = open('input.txt', 'r')


N = int(sys.stdin.readline().rstrip())
i = 1
mem = ['666']

while True:
    cnt = 0
    temp = list(str(i))

    for k in range(len(temp)):
        if temp[len(temp) - 1 - k] == '6':
            cnt += 1
        else:
            break

    if i % 10 == 6:
        for j in range(10 ** (cnt)):
            mem.append(str(i) + '6' * (3 - cnt) + '0' * (cnt - len(str(j))) + str(j))
        if len(mem) > N:
            break
    else:
        mem.append(str(i) + '666')
        if len(mem) > N:
            break
    i += 1

result = list(map(int, mem))
print(result[N-1])
