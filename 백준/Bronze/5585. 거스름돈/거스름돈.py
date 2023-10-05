import sys
#sys.stdin = open('bj5585.txt', 'r')

price = int(input())

remain = 1000 - price
total = 0

coin, remain = divmod(remain, 500)
total += coin
coin, remain = divmod(remain, 100)
total += coin
coin, remain = divmod(remain, 50)
total += coin
coin, remain = divmod(remain, 10)
total += coin
coin, remain = divmod(remain, 5)
total += coin
coin, remain = divmod(remain, 1)
total += coin

print(total)