import sys

#sys.stdin = open('input.txt', 'r')
N = int(sys.stdin.readline().rstrip())
arr = list(sys.stdin.readline().rstrip())
stack = []
d = {}

for i in range(N):
    num = int(sys.stdin.readline().rstrip())
    d[chr(65+i)] = num

for i in arr:
    if 65 <= ord(i) <= 97:
        stack.append(d[i])
    else:
        b = stack.pop()
        a = stack.pop()
        if i == '*':
            stack.append(a * b)
        elif i == '+':
            stack.append(a + b)
        elif i == '/':
            stack.append(a / b)
        elif i == '-':
            stack.append(a - b)

print('{:0.2f}'.format(stack[0]))