import sys
#sys.stdin = open('bj14235.txt', 'r')

A, B = map(int, input().split())

if A > B :
    print('>')

if A < B :
    print('<')

if A == B :
    print('==')