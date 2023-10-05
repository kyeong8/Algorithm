import sys
from collections import deque

#sys.stdin = open('input.txt', 'r')

arr = deque([[]])
mem = []

for i in range(4):
    arr.append(deque(map(int, input())))

command = []
k = int(input().rstrip())

for i in range(k):
    command.append(list(map(int, input().split())))

for i in range(k):
    mem.append([command[i][0], command[i][1], 0])

    while len(mem) > 0:
        num, rotate, pre = mem.pop()

        left = num-1
        if pre != left and left > 0:
            if arr[left][2] != arr[left+1][6]:
                mem.append([left, -rotate, num])

        right = num + 1
        if pre != right and right < 5:
            if arr[right][6] != arr[right-1][2]:
                mem.append([right, -rotate, num])

        if rotate > 0:
            temp = arr[num].pop()
            arr[num].appendleft(temp)
        else:
            temp = arr[num].popleft()
            arr[num].append(temp)

answer = 0
for i in range(4):
    if arr[i+1][0] == 1:
        answer += 2 ** i

print(answer)