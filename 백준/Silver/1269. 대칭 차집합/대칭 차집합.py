import sys
#sys.stdin = open('input.txt', 'r')

N, M = map(int, sys.stdin.readline().split())
a = []
b = []

a.extend(list(map(int,sys.stdin.readline().split())))
b.extend(list(map(int,sys.stdin.readline().split())))

result = list((set(a) | set(b)) - (set(a) & set(b)))
print(len(result))
