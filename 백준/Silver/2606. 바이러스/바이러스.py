import sys
from collections import deque


def breadth_first_search(graph, root):
    visited = []

    discovered = []
    queue = deque([root])
    discovered.append(root)

    while len(queue) > 0:
        node = queue.popleft()
        visited.append(node)
        undiscovered = set(graph[node]).difference(set(discovered))

        if len(undiscovered) > 0:
            for elem in sorted(undiscovered):
                queue.append(elem)
                discovered.append(elem)

    return visited


N = int(input())
M = int(input())

_graph = dict()
adjacency = []

for j in range(1, N+1):
    _graph[str(j)] = []

for _ in range(M):
    edge = list(map(str, input().split()))

    if edge[0] not in _graph:
        _graph[edge[0]] = [edge[1]]

    else:
        adjacency.extend(_graph[edge[0]])
        adjacency.extend([edge[1]])
        _graph[edge[0]] = adjacency[:]

    adjacency.clear()

    if edge[1] not in _graph:
        _graph[edge[1]] = [edge[0]]

    else:
        adjacency.extend(_graph[edge[1]])
        adjacency.extend([edge[0]])
        _graph[edge[1]] = adjacency[:]

    adjacency.clear()


result = breadth_first_search(_graph, '1')


print(len(result)-1)