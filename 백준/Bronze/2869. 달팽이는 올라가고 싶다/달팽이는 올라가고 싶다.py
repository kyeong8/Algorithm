import sys
#sys.stdin = open('test.txt', 'r')

A, B, C = map(int, sys.stdin.readline().split())

if ((C - A) // (A - B)) < ((C - A) / (A - B)) < ((C - A) // (A - B)) + 1:
    result = ((C - A) // (A - B)) + 2
else:
    result = (C-A) // (A-B) + 1


print(result)
