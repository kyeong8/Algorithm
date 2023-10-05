import sys
#sys.stdin = open('input.txt', 'r')

def push(stack : list, X : int):
    stack.append(X)
    return stack

def pop(stack : list):
    if len(stack) == 0:
        return -1
    result = stack.pop(-1)
    return result

def size(stack : list):
    return len(stack)

def empty(stack : list):
    if len(stack) == 0:
        return 1
    else:
        return 0

def top(stack : list):
    if len(stack) == 0:
        return -1
    return stack[len(stack) - 1]

N= int(sys.stdin.readline().rstrip())
stack = []

for i in range(N):
    temp = list(sys.stdin.readline().split())
    if temp[0] == 'push':
        stack = push(stack, temp[1])
    elif temp[0] == 'pop':
        result = pop(stack)
        print(result)
    elif temp[0] == 'size':
        result = size(stack)
        print(result)
    elif temp[0] == 'empty':
        result = empty(stack)
        print(result)
    elif temp[0] == 'top':
        result = top(stack)
        print(result)