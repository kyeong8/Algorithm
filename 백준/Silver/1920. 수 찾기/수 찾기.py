def binarySearch(array, target, left, right):
    
    if left > right :
        print(0)
        return None

    middle_inx = (left+right)//2

    if target == array[middle_inx]:
        print(1)
    elif array[middle_inx]>target:
        binarySearch(array, target, left, middle_inx-1)
    else:
        binarySearch(array, target, middle_inx+1, right)
    

n = int(input())

array = sorted(list(map(int, input().split())))

m = int(input())

b = list(map(int, input().split()))

left = 0
right = len(array)-1

for target in b:
    binarySearch(array, target, left, right)

