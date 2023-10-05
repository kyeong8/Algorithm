import sys
#sys.stdin = open('test.txt', 'r')

A = list(sys.stdin.readline().rstrip())
B = [0 for _ in range(len(A))]

for i in range(len(A)):
    if A[i] == 'A' or A[i] == 'B' or A[i] == 'C':
        B[i] = 3
    elif A[i] == 'D' or A[i] == 'E' or A[i] == 'F':
        B[i] = 4
    elif A[i] == 'G' or A[i] == 'H' or A[i] == 'I':
        B[i] = 5
    elif A[i] == 'J' or A[i] == 'K' or A[i] == 'L':
        B[i] = 6
    elif A[i] == 'M' or A[i] == 'N' or A[i] == 'O':
        B[i] = 7
    elif A[i] == 'P' or A[i] == 'Q' or A[i] == 'R' or A[i] == 'S':
        B[i] = 8
    elif A[i] == 'T' or A[i] == 'U' or A[i] == 'V':
        B[i] = 9
    elif A[i] == 'W' or A[i] == 'X' or A[i] == 'Y' or A[i] == 'Z':
        B[i] = 10

total = 0
for j in range(len(B)):
    total = total + B[j]

print(total)

