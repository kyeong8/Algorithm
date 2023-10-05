import sys
#sys.stdin = open('bj14235.txt', 'r')

#N = int(sys.stdin.readline().rstrip())

while True:
    try:
        A, B = map(int, sys.stdin.readline().split())
    except:
        break
        
    print(A + B)
        