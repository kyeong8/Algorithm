import sys
import math
#sys.stdin = open('input.txt', 'r')

R = int(sys.stdin.readline().rstrip())

print('{:.6f}'.format(R ** 2 * math.pi))
print('{:.6f}'.format(2 * R ** 2))
