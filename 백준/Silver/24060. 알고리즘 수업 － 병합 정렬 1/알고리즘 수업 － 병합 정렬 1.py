import sys

def merge_sort(A, p, r):
    if(p < r and count <= K):
        q = (p + r) // 2
        merge_sort(A, p, q)
        merge_sort(A, q + 1, r)
        merge(A, p, q, r)
        
def merge(A, p, q, r):
    global count, result
    i, j = p, q + 1
    tmp = []
    
    while i <= q and j <= r:
        if(A[i] <= A[j]):
            tmp.append(A[i])
            i += 1
        else:
            tmp.append(A[j])
            j += 1
        
    while i <= q:
        tmp.append(A[i])
        i += 1
    
    while j <= r:
        tmp.append(A[j])
        j += 1
    
    i, t = p, 0
    
    while i <= r:
        A[i] = tmp[t]
        count += 1
        if count == K:
            print(A[i])
            exit()
        i += 1
        t += 1

#sys.stdin = open('bj-solve\input.txt', 'r')

N, K= map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))

count = 0
merge_sort(A, 0, N - 1)
print(-1)
