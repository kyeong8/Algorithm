import sys
#sys.stdin = open('test.txt', 'r')

N = int(sys.stdin.readline().rstrip())
i = 0
total = 0
while N > total + 1:
    i = i + 1
    total = total + 6 * i
print(i+1)
