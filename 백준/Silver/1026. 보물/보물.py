import sys


def bubble_sort(unordered):
    iteration = len(unordered) - 1
    for i in range(iteration):
        for j in range(iteration - i):
            if unordered[j] > unordered[j + 1]:
                unordered[j], unordered[j + 1] = unordered[j + 1], unordered[j]


N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

S = 0

bubble_sort(A)

for k in range(N):
    S += A[k] * B.pop(B.index(max(B)))

print(S)
