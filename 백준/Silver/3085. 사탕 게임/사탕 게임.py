import sys
input = sys.stdin.readline
# count는 data에서 오른쪽,아래로 인점한 것과 바꿨을 때 가장 긴 연속한 부분을 찾아내는 함수
def count(data):
    Max = 1
    for i in range(n):
        cnt = 1
        for j in range(1,n):
            if data[i][j] == data[i][j-1]:
                cnt += 1
            else:
                cnt = 1
            Max = max(Max,cnt)
        cnt = 1
        for j in range(1,n):
            if  data[j][i] == data[j-1][i]:
                cnt += 1
            else:
                cnt = 1
            Max = max(Max,cnt)

    return Max
# 오른쪽 하고 아래부분만 신경써주면된다.
n = int(input())
data = [list(input()) for _ in range(n)]
ans = 0
for i in range(n):
    for j in range(n):
        # 열 바꾸기
        if j+1 < n:
        	# 인점한 것과 바꾸기
            data[i][j], data[i][j+1] = data[i][j+1], data[i][j]
            temp=count(data)
            ans = max(ans,temp)
            # 바꿨던 것을 다시 원래대로 돌려놓기
            data[i][j], data[i][j+1] = data[i][j+1], data[i][j]
        # 행 바꾸기
        if i+1 < n:
        	# 인점한 것과 바꾸기
            data[i][j], data[i+1][j] = data[i+1][j], data[i][j]
            temp=count(data)
            ans = max(ans,temp)
            # 바꿨던 것을 다시 원래대로 돌려놓기
            data[i][j], data[i+1][j] = data[i+1][j], data[i][j]
print(ans)