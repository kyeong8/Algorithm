import sys
#sys.stdin = open('bj1931.txt', 'r')


def selector(s):
    selected_act = 0
    ans = [selected_act]

    for act in range(1, len(s)):
        if s[act][0] >= s[selected_act][1]:
            selected_act = act
            ans.append(selected_act)

    return ans


N = int(input())
acts = []
for _ in range(N):
    a, b = map(int, sys.stdin.readline().split())
    acts.append((a, b))

acts.sort(key=lambda x: (x[1], x[0]))

print(len(selector(acts)))