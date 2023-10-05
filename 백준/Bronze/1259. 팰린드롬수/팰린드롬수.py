import sys

#sys.stdin = open('input.txt', 'r')
arr = sys.stdin.readline().rstrip()

while arr != '0':
    for i in range(len(arr)//2 + 1):
        if arr[i] != arr[-1-i]:
            print('no')
            break
    else:
        print('yes')
    arr = sys.stdin.readline().rstrip()