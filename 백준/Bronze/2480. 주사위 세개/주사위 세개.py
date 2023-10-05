import sys
#sys.stdin = open('bj14235.txt', 'r')

A, B, C = map(int, input().split())

if A == B == C:
    print(10000 + A * 1000)

elif A == B or A == C or B == C:
    if A == B:
        print(1000 + A * 100)
    elif B == C:
        print(1000 + B * 100)
    elif C == A:
        print(1000 + C * 100)

else:
    if A > B and A > C:
        print(A * 100)
    elif B > C and B > A:
        print(B * 100)
    elif C > B and C > A:
        print(C * 100)

