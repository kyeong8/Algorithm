N = int(input())
total = 1

for i in range(1, N+1):
    total = total*i

total = list(str(total))

cnt = 0

while total[-1] == '0':
    cnt += 1
    total.pop(-1)
print(cnt)