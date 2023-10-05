import sys
#sys.stdin = open('test.txt', 'r')

arr = list(sys.stdin.readline().rstrip())
set = list(set(arr))
dict = {}
cnt = 0
for i in range(len(set)):
    cnt = arr.count(set[i].lower())
    cnt = cnt + arr.count(set[i].upper())
    dict[ord(set[i].upper())] = cnt
    cnt = 0

temp = sorted(dict.items(), key=lambda x: x[1], reverse=True)

flag = 0

if len(temp) > 1:
    if temp[0][1] == temp[1][1]:
        print('?')
    else:
        print(chr(temp[0][0]))
else:
    print(chr(temp[0][0]))

