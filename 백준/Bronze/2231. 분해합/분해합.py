import sys
#sys.stdin = open('input.txt', 'r')

arr = list(map(str, sys.stdin.readline().rstrip()))
num = ''.join(arr)
generator = []

for i in range(1, 9*len(arr)+1):
    
    value = int(num) - i
    
    if value < 0:
        break
        
    value = list(map(int, str(value)))
      
    if i == sum(value):
        generator.append(''.join(map(str, value)))


if len(generator) == 0:
    print(0)
else:
    print(min(generator))