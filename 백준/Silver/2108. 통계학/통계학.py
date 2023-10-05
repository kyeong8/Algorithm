import sys
#sys.stdin = open('input.txt', 'r')


N = int(sys.stdin.readline().rstrip())
temp = 0
arr = []
mem = [0]
sorting1 = [0 for _ in range(8001)]

for i in range(N):
    x = int(sys.stdin.readline().rstrip())
    arr.append(x)
    sorting1[x + 4000] += 1


total = sum(arr)

if (total / N - total // N) >= 0.5:
    print(total // N + 1)
else:
    print(round(total / N))

index = (N + 1)//2
cnt = 0
Min = 0
Max = 0
flag = 0
flag1 = 0
center = 0

for i in range(8001):
    if sorting1[i] != 0 and flag == 0:
        Min = i - 4000
        Max = i - 4000
        cnt += abs(sorting1[i])
        flag = 1
    elif sorting1[i] != 0 and flag == 1:
        if (i - 4000) > Max:
            Max = i - 4000
        cnt += abs(sorting1[i])
    if cnt >= index and flag1 == 0:
        center = i
        flag1 = 1

print(center - 4000)
temp = 0

for i in range(8001):
    if sorting1[i] > temp:
        mem = [0]
        mem[0] = i - 4000
        temp = sorting1[i]
    elif sorting1[i] == temp:
        if not (i - 4000) in mem:
            mem.append(i - 4000)


if len(mem) > 1:
    print(mem[1])
else:
    print(mem[0])


print(Max - Min)
