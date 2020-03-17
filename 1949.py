# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 17.
# time : 오후 6:51
# problem : https://www.acmicpc.net/problem/1949
# problem type :

# 수많은 런타임 에러 속에서 고통받았던 문제
# 쉬운 문제 같은데 왜 이렇게 많이 틀렸을까
# 선택하고 선택하는 것은 쉽게 배제 가능하다.
# 선택 안하고 선택 안하고 선택 안하는 경우를 배제해야 하는데, 그 경우를 생각하다가 많이 틀린 것 같다.
# 하지만 그 경우는 자연스럽게 더 큰 값을 선택하는 dp에 의해 010이나 101 등의 경우로 대체될 텐데 그 생각을 못했다.

def dfs(node, parent, best):
    global dp

    if dp[node][best] != -1: return dp[node][best]

    dp[node][best] = best * num_people[node]
    for next_node in linked[node]:
        if next_node == parent: continue
        if best == 1: # 지금 우수 마을이면 자식은 우수마을이 아니어야 한다.
            dp[node][best] += dfs(next_node, node, 0)
        else:
            dp[node][best] += max(dfs(next_node, node, 1), dfs(next_node, node, 0)) # 지금 우수마을이 아니면 자식은 우수마을이거나 우수마을이 아닌 것 중 max이다.
    return dp[node][best]

import sys
sys.setrecursionlimit(10 ** 9)

n = int(sys.stdin.readline())
num_people = [0] + list(map(int, sys.stdin.readline().split()))
linked = [[] for _ in range(n+1)]

for i in range(n-1):
    x, y = map(int, sys.stdin.readline().split())
    linked[x].append(y)
    linked[y].append(x)

dp = [[-1] * 2 for _ in range(n+1)]
print(max(dfs(1, -1, -1, 0), dfs(1, -1, -1, 1))) # 우수마을로 시작하는 것과 우수마을이 아닌 걸로 시작하는 경우 중 max