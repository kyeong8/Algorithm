import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
total = [[0]*3 for i in range(100001)]
total[1][0], total[1][1], total[1][2] = 1, 1, 1

for i in range(2, N+1):
    total[i][0] = (total[i-1][0] + total[i-1][1] + total[i-1][2]) % 9901
    total[i][1] = (total[i-1][0] + total[i-1][2]) % 9901
    total[i][2] = (total[i-1][0] + total[i-1][1]) % 9901

print(sum(total[N]) % 9901)