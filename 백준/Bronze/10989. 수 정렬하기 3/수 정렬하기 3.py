import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
counting = [0 for _ in range(10001)]

for i in range(N):
    counting[int(sys.stdin.readline().rstrip())] += 1

for i in range(len(counting)):
    if counting[i] != 0:
        for _ in range(counting[i]):
            print(i)
