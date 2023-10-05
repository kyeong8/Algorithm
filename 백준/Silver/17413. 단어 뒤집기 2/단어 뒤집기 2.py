import sys
#sys.stdin = open('input.txt', 'r')

S = list(sys.stdin.readline().rstrip())
mem = []
s = ''
flag = 0
for num, i in enumerate(S):
    if i == '<':
        if len(s) > 0:
            arr = s[::-1]
            mem.append(arr)
            s = ''
        flag = 1
        mem.append(i)
    elif i == '>':
        flag = 0
        mem.append(i)
    elif flag == 1:
        mem.append(i)
    elif flag == 0:
        if num == len(S) - 1:
            s += i
            arr = s[::-1]
            mem.append(arr)
        elif i == ' ':
            arr = s[::-1]
            mem.append(arr)
            mem.append(i)
            s = ''
        else:
            s += i

print(''.join(mem))