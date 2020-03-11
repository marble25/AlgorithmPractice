# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 11.
# time : 오후 9:09
# problem : https://www.acmicpc.net/problem/2213
# problem type : Tree, DP

# 깔끔하게 1트만에 맞은 문제

import sys
sys.setrecursionlimit(1000000)
n = int(sys.stdin.readline())

weights = [0] + list(map(int, sys.stdin.readline().split()))
linked = [[] for _ in range(n+1)]

for i in range(n-1):
    x, y = map(int, sys.stdin.readline().split())
    linked[x].append(y)
    linked[y].append(x)

dp = [[-1] * 2 for _ in range(n+1)]
visited = [0] * (n+1)

# dp값을 구하는 함수
def dfs(parent, x, checked):
    global visited
    visited[x] = 1

    if dp[x][checked] != -1: return dp[x][checked] # 이미 값이 있으면 그 값 return
    dp[x][checked] = weights[x] if checked == 1 else 0 # checked가 1이면 정점 가중치를 더해줌
    for next_node in linked[x]:
        if next_node == parent: continue # 부모 노드로 가지 않도록

        if checked == 1: # 현재 정점이 독립집합에 속한다면 그와 연결된 정점은 포함되면 안된다.
            dp[x][checked] += dfs(x, next_node, 0)
        else: # 현재 정점이 독립집합에 속하지 않으면 그와 연결된 정점은 포함되든 포함되지 않든 상관없다.
            dp[x][checked] += max(dfs(x, next_node, 0), dfs(x, next_node, 1))

    return dp[x][checked]

arr = []

# 찾은 dp를 가지고 탐색하여 최대 독립집합을 구하는 함수
def search(parent, x, checked):
    for next_node in linked[x]:
        if next_node == parent: continue # 부모 노드로 가지 않도록

        if checked == 1:
            search(x, next_node, 0)
        elif dp[next_node][0] > dp[next_node][1]: # 더 큰 값이 나온 경로를 택해서 감
            search(x, next_node, 0)
        else:
            search(x, next_node, 1)
            arr.append(next_node)

print(max(dfs(0, 1, 0), dfs(0, 1, 1)))

if dp[1][0] > dp[1][1]:
    search(0, 1, 0) # 1 포함 X
else:
    arr.append(1)
    search(0, 1, 1) # 1 포함

arr.sort()
print(' '.join(map(str, arr)))