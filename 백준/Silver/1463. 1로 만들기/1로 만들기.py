import sys
#sys.stdin = open('input.txt', 'r')

mem = [0 for _ in range(1000001)]
for i in range(1, 1000001):
    Min = 1000000
    if i == 1:
        mem[i] = 0
    else:
        if i % 3 == 0:
            if mem[i//3] < Min:
                Min = mem[i//3]
        if i % 2 == 0:
            if mem[i//2] < Min:
                Min = mem[i//2]
        if mem[i - 1] < Min:
            Min = mem[i - 1]
        mem[i] = Min + 1

N = int(sys.stdin.readline().rstrip())
print(mem[N])