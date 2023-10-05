import sys
#sys.stdin = open('bj14235.txt', 'r')

A = list(map(int, input()))
B = list(map(int, input()))
print(A[2]*B[2]+A[1]*B[2]*10+A[0]*B[2]*100)
print(A[2]*B[1]+A[1]*B[1]*10+A[0]*B[1]*100)
print(A[2]*B[0]+A[1]*B[0]*10+A[0]*B[0]*100)
print((A[2]*B[2]+A[1]*B[2]*10+A[0]*B[2]*100) + (A[2]*B[1]+A[1]*B[1]*10+A[0]*B[1]*100) * 10 + (A[2]*B[0]+A[1]*B[0]*10+A[0]*B[0]*100) * 100)
