import sys

#sys.stdin = open('input.txt', 'r')
arr = list(sys.stdin.readline().rstrip())
stack = []
result = []

for i in arr:
    if i == '*' or i == '/':
        if stack:
            if stack[-1] == '*' or stack[-1] == '/':
                result.append(stack.pop())
        stack.append(i)
    if i == '(':
        stack.append(i)
    elif 65 <= ord(i) <= 97:
        result.append(i)
    elif i == '+' or i == '-':
        while True:
            if not stack:
                break
            elif stack[-1] == '(':
                break
            elif stack:
                result.append(stack.pop())
        stack.append(i)
    elif i == ')':
        while stack[-1] != '(':
            result.append(stack.pop())
        stack.pop()

while stack:
    result.append(stack.pop())

print(''.join(result))
