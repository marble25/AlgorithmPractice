# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 27.
# time : 오후 11:08
# problem : https://www.acmicpc.net/problem/2533
# problem type : DP

# 메모리 초과, 시간초과, 출력초과, 런타임 에러 등 각종 경우를 다 겪어봄
# 때로는 pypy보다 python이 더 잘 동작할 수 있음

import sys

sys.setrecursionlimit(1000010)

n = int(sys.stdin.readline())
linked = []
for i in range(n+1):
    linked.append([])

visited = [-1] * (n+1)
for i in range(n-1):
    x, y = map(int, sys.stdin.readline().split())
    linked[x].append(y)
    linked[y].append(x)

visited[1] = 1
dp = [[-1] * 2 for _ in range(n+1)]

# x노드가 early adopter인 경우(1)과 early adopter가 아닌 경우(0)으로 나누어서 처리
def dfs(x, is_early_adopter):
    global linked, visited, dp

    # 이미 값이 있으면 dp 값 리턴
    if dp[x][is_early_adopter] != -1: return dp[x][is_early_adopter]
    num_early_adopter = is_early_adopter
    for node in linked[x]:
        if visited[node] == -1:
            visited[node] = 1
            if is_early_adopter == 1: # 자신이 early adopter이면 자식이 어떤 것이든 상관 없으므로 가장 작은 값을 취함
                num_early_adopter += min(dfs(node, 0), dfs(node, 1))
            else: # 자신이 early adopter이 아니면 자식은 무조건 early adopter이어야 함
                num_early_adopter += dfs(node, 1)
            visited[node] = -1

    dp[x][is_early_adopter] = num_early_adopter
    return num_early_adopter

# 1이 early adopter인 경우와 아닌 경우 중 최소값 출력
print(min(dfs(1, 0), dfs(1, 1)))