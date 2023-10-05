import sys
#sys.stdin = open('input.txt', 'r')

while True:
    arr = list(sys.stdin.readline().rstrip('\n'))
    if not arr:
        break

    big_alpha, small_alpha, num, space = 0, 0, 0, 0
    for i in arr:
        if 65 <= ord(i) <= 90:
            big_alpha += 1
        elif 97 <= ord(i) <= 122:
            small_alpha += 1
        elif i == ' ':
            space += 1
        elif i.isdigit():
            num += 1
    print(small_alpha, big_alpha, num, space)