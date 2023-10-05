import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
human = []
rank = [[] for _ in range(N)]

for i in range(N):
    human.append(list(map(int, sys.stdin.readline().split())))

for i in range(N):
    index = 0
    for j in range(N):
        if human[i][0] < human[j][0] and human[i][1] < human[j][1]:
            index += 1
    rank[index].append(human[i])

for i in range(N):
    for j in range(N):
        if human[i] in rank[j]:
            print(j + 1, end=' ')