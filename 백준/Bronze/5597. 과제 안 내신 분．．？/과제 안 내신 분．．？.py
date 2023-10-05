import sys
#sys.stdin = open('input.txt', 'r')

arr = set(i for i in range(1, 31))
result = []
for _ in range(28):
    result.append(int(sys.stdin.readline().rstrip()))

print(min(arr - set(result)))
print(max(arr - set(result)))