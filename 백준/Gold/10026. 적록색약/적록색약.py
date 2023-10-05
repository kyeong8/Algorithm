import sys
import copy


def depth_first_search(graph, row, col):
    stack = [(row, col)]
    move = [[0, -1], [0, 1], [-1, 0], [1, 0]]

    color = graph[row][col]
    graph[row][col] = 'X'

    while len(stack) > 0:
        row, col = stack.pop()
        for m in range(4):
            next_row, next_col = row, col
            next_row += move[m][0]
            next_col += move[m][1]
            if not check_move(graph, next_row, next_col, color):
                continue

            stack.append((next_row, next_col))
            graph[next_row][next_col] = 'X'


def check_move(graph, row, col, color):
    if row < 0 or row >= size:
        return False
    if col < 0 or col >= size:
        return False
    if graph[row][col] != color:
        return False
    if graph[row][col] == 'X':
        return False

    return True



size = int(input())
count1 = 0
count2 = 0

graph1 = [[] for _ in range(size)]

for i in range(size):
    graph1[i] = list(input())

graph2 = copy.deepcopy(graph1)

for i in range(size):
    for j in range(size):
        if graph1[i][j] != 'X':
            depth_first_search(graph1, i, j)
            count1 += 1

        if graph2[i][j] == 'G':
            graph2[i][j] = 'R'

for i in range(size):
    for j in range(size):
        if graph2[i][j] != 'X':
            depth_first_search(graph2, i, j)
            count2 += 1

print(count1, count2)