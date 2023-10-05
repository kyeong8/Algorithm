import sys

#sys.stdin = open('input.txt', 'r')
alpha = [0 for i in range(26)]
arr = list(sys.stdin.readline().rstrip())

for i in arr:
    alpha[ord(i)-97] += 1

print(*alpha, sep=' ')