import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
deque = []

for i in range(N):
    S = list(sys.stdin.readline().split())
    if S[0] == 'push_front':
        temp = [S[1]]
        temp.extend(deque)
        deque = temp
    elif S[0] == 'push_back':
        deque.append(S[1])
    elif S[0] == 'front':
        if len(deque) == 0:
            print(-1)
            continue
        print(deque[0])
    elif S[0] == 'back':
        if len(deque) == 0:
            print(-1)
            continue
        print(deque[-1])
    elif S[0] == 'size':
        print(len(deque))
    elif S[0] == 'empty':
        if len(deque) == 0:
            print(1)
        else:
            print(0)
    elif S[0] == 'pop_front':
        if len(deque) == 0:
            print(-1)
            continue
        print(deque.pop(0))
    elif S[0] == 'pop_back':
        if len(deque) == 0:
            print(-1)
            continue
        print(deque.pop(-1))
