import sys

#sys.stdin = open('input.txt', 'r')


def combination(index, mem, k, _human, _visited, _team):
    if len(mem) == k:
        _team.append(mem[:])
        return

    for i in range(index, len(_human)):
        if not _visited[i]:
            _visited[i] = 1
            mem.append(_human[i])
            combination(i+1, mem, k, _human, _visited, _team)
            mem.pop()
            _visited[i] = 0


arr = []
N = int(input().rstrip())
for _ in range(N):
    arr.append(list(map(int, input().split())))

team = []

human = [i for i in range(N)]
combination(0, [], N//2, human, [0 for _ in range(N)], team)

answer = []
for i in team:
    total = 0
    point = []
    combination(0, [], 2, i, [0 for _ in range(N//2)], point)
    for j in point:
        row, col = j
        total += arr[row][col]
        total += arr[col][row]

    answer.append(total)


_min = float("inf")
flag = 0
num = len(answer)-1
for i in range(num//2+1):
    if abs(answer[i] - answer[num-i]) < _min:
        _min = abs(answer[i] - answer[num-i])
        flag = i

print(abs(answer[flag] - answer[num-flag]))