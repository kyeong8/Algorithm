import sys
#sys.stdin = open('test.txt', 'r')

A, B = list(sys.stdin.readline().split())
A = list(A)
B = list(B)

for i in range(1, 4):
    if A[len(A)-i] > B[len(B)-i]:
        print(''.join((A[::-1])))
        break
    elif A[len(A)-i] < B[len(B)-i]:
        print(''.join((B[::-1])))
        break
    else:
        pass

