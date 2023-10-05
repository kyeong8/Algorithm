def hanoi(disks, src, dst, extra):
    if disks == 1:
        hanoi.count += 1
        hanoi.moves.append((src, dst))
    else:
        hanoi(disks-1, src, extra, dst)
        hanoi.count += 1
        hanoi.moves.append((src, dst))
        hanoi(disks-1, extra, dst, src)


hanoi.count = 0
hanoi.moves = []

disks = int(input())
hanoi(disks, 1, 3, 2)

print(hanoi.count)
for i in hanoi.moves:
    for j in i:
        print(j, end=' ')
    print('')