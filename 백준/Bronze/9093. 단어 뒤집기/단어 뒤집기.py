import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())

for i in range(N):
    temp = list(sys.stdin.readline().strip())

    while True:
        if ' ' in temp:
            index = temp.index(' ')
            for j in range(index):
                print(temp[index - 1], end='')
                temp.pop(index - 1)
                index -= 1
            print(temp[0], end='')
            temp.pop(0)
        else:
            for k in range(len(temp)):
                print(temp[-1], end='')
                temp.pop(-1)
        if len(temp) == 0:
            break
    print()