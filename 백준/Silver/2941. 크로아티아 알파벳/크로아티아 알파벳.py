import sys
#sys.stdin = open('test.txt', 'r')

alpha = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
A = [sys.stdin.readline().rstrip()]

for i in alpha:
    if i in A[0]:
        A[0] = A[0].replace(i, '1')

print(len(list(A[0])))
