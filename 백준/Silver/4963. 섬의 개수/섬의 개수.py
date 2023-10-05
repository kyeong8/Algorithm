import sys
sys.setrecursionlimit(10**6)
#sys.stdin = open("bj-solve\input.txt", 'r')
input = sys.stdin.readline

def dfs(graph, row, col):
    graph[row][col] = '0'
        

    for i, j in move:
        new_row = i + row
        new_col = j + col
        if check(graph, new_row, new_col):
            dfs(graph, new_row, new_col)



def check(graph, row, col):
    if row < 0 or row >= h:
        return False
    elif col < 0 or col >= w:
        return False
    elif graph[row][col] == '0':
        return False
    return True

move = [[0, -1], [0, 1], [-1, 0], [1, 0], [-1, -1], [1, -1], [-1, 1], [1, 1]]

while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        exit()
    
    graph = []
    for i in range(h):
        graph.append(list(input().split()))
    
    cnt = 0
    for i in range(h):
        for j in range(w):
            if graph[i][j] == '1':
                dfs(graph, i, j)
                cnt += 1
    print(cnt)