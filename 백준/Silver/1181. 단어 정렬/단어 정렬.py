import sys
#sys.stdin = open('input.txt', 'r')

N = int(sys.stdin.readline().rstrip())
d = {}
for i in range(N):
    word = sys.stdin.readline().rstrip()
    d[word] = len(word)

mem = sorted(d.items(), key=lambda x:(x[1], x[0]))

for i in range(len(mem)):
    print(mem[i][0])
