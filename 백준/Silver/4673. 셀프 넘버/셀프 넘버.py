import sys
#sys.stdin = open('test.txt', 'r')

def d(a: int):
    m = a
    while m != 0:
        n = m % 10
        m = m // 10

        if m > 9:
            a = a + n
        else:
            a = a + m
            a = a + n
            m = m // 10

    return a

arr1 = [i for i in range(1, 10001)]
arr2 = []

for i in range(1, 10001):
    arr2.append(d(i))

complement = list(set(arr1) - set(arr2))

complement.sort()

for i in range(len(complement)):
    print(complement[i])