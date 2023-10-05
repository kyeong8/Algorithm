import sys
#sys.stdin = open('bj12865.txt', 'r')


def knapsack(capacity, item):
    # capacity: current capacity of the knapsack, [0.._capacity]
    # item: index of the item to be considered, [0.._number-1]
    # _number: number of items
    # _capacity: capacity of the knapsack
    # _weight: weight list of the items
    # _value: value list of the items

    if capacity == 0 or item >= N:
        return 0

    if _weight[item] > capacity:
        return knapsack(capacity, item+1)

    if memo.get((capacity, item)) is None:
        with_the_item = _value[item] + knapsack(capacity - _weight[item], item+1)
        without_the_item = knapsack(capacity, item+1)

        memo[(capacity, item)] = max(with_the_item, without_the_item)

    return memo[(capacity, item)]


N, W = map(int, input().split())
_weight = []
_value = []

memo = {}


for _ in range(N):
    a, b = map(int, input().split())
    _weight.append(a)
    _value.append(b)

print(knapsack(W, 0))