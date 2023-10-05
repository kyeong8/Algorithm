import sys
#sys.stdin = open('input.txt', 'r')

b = list(sys.stdin.readline().rstrip())
a = []
N = int(sys.stdin.readline().rstrip())
index = len(b)

for i in range(N):
    temp = list(sys.stdin.readline().split())
    if temp[0] == 'L':
        if index == 0:
            pass
        else:
            index -= 1
            a.append(b[index])
            b.pop(index)
    elif temp[0] == 'D':
        if len(a) == 0:
            pass
        else:
            b.append(a[len(a) - 1])
            a.pop(len(a) - 1)
            index += 1
    elif temp[0] == 'B':
        if index != 0:
            index -= 1
            b.pop(index)
    elif temp[0] == 'P':
        b.append(temp[1])
        index += 1

a.reverse()

print(''.join(b) + ''.join(a))

