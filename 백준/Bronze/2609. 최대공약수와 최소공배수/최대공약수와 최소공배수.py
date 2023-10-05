import sys

#sys.stdin = open('input.txt', 'r')
N, M = map(int, sys.stdin.readline().split())
temp = []
for i in range(1, int(N**0.5 + 1)):
    if N % i == 0:
        temp.append(i)
        temp.append(N // i)

a = set(temp)

temp = []
for i in range(1, int(M**0.5 + 1)):
    if M % i == 0:
        temp.append(i)
        temp.append(M // i)

b = set(temp)

intersection = list(a & b)
print(max(intersection))
Max = max([N, M])

i = 1
while True:
    if (Max * i) % N == 0 and (Max * i) % M == 0:
        print(Max * i)
        break
    i += 1