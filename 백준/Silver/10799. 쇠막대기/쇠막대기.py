import sys

#sys.stdin = open('input.txt', 'r')

arr = list(sys.stdin.readline().rstrip())
stack = []
combo = 0
total = 0

for index, i in enumerate(arr):
    if i == '(':
        total += 1
        stack.append(index)
        combo = index
    else:
        if (combo + 1) == index:
            total -= 1
            stack.pop()
            total += len(stack)
        else:
            stack.pop()

print(total)