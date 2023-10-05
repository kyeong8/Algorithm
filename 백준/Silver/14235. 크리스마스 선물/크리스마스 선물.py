import sys
#sys.stdin = open('bj14235.txt', 'r')


class MaxHeap:
    def __init__(self, data_list=None):
        self.h = [0]
        if data_list is not None:
            self.h.extend(data_list)

        for i in range(self.size() // 2, 0, -1):
            self.max_heapify(i)

    def size(self):
        return len(self.h) - 1

    def max_heapify(self, k):
        left = k * 2
        right = k * 2 + 1

        largest = k
        if left <= self.size() and self.h[left] > self.h[largest]:
            largest = left
        if right <= self.size() and self.h[right] > self.h[largest]:
            largest = right

        if largest != k:
            self.h[k], self.h[largest] = self.h[largest], self.h[k]
            self.max_heapify(largest)

    def heap_sort(self):
        save = self.h[:]
        sorted_list = self.h[1:]

        for i in range(self.size(), 0 , -1):
            self.h[1], self.h[i] = self.h[i], self.h[1]
            sorted_list[i-1] =  self.h[i]
            self.h.pop()
            self.max_heapify(1)

        self.h = save
        return sorted_list

    def pop(self):
        if self.size() == 0:
            return None

        item = self.h[1]
        self.h[1] = self.h[self.size()]
        self.h.pop()
        self.max_heapify(1)

        return item

    def insert(self, item):
        self.h.append(item)

        k = self.size()
        while k > 1 and self.h[k] > self.h[k//2]:
            self.h[k], self.h[k//2] = self.h[k//2], self.h[k]
            k //= 2

N = int(input())
h = MaxHeap()

for _ in range(N):
    gift = list(map(int, input().split()))

    if gift[0] == 0:
        if h.size() > 0:
            print(h.pop())
        else:
            print(-1)
    else:
        for i in range(gift[0]):
            h.insert(gift[i+1])
