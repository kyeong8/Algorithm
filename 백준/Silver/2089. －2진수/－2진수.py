import sys
#sys.stdin = open('input.txt', 'r')


def find(num):
    res = 0
    if num > 0:
        i = 0
        while res < num:
            res += 2 ** i
            i += 2
    else:
        i = 1
        while res > num:
            res += -(2 ** i)
            i += 2
    return i-2


def value(exp):
    return ((-1) ** exp) * (2 ** exp)


result = []
n = int(sys.stdin.readline().rstrip())
i = find(n)

if i == 0:
    result.append(i)
elif i < 0:
    print(0)
else:
    result.append(i)
    temp = n - value(i)
    i = find(temp)
    if i >= 0:
        result.append(i)
        while True:
            temp = temp - value(i)
            i = find(temp)
            if i < 0:
                break
            result.append(i)

if result:
    index = max(result)

    while index >= 0:
        if index in result:
            print(1, end='')
        else:
            print(0, end='')
        index -= 1