import sys
#sys.stdin = open('input.txt', 'r')

arr = list(sys.stdin.readline().rstrip())
for index, i in enumerate(arr):
    if i.islower() and ord(i) + 13 > 122:
        arr[index] = chr(ord(i) + 13 - 122 + 96)
    elif i.isupper() and ord(i) + 13 > 90:
        arr[index] = chr(ord(i) + 13 - 90 + 64)
    elif i.isalpha():
        arr[index] = chr(ord(i) + 13)
print(*arr, sep='')