# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 9.
# time : 오후 2:45
# problem : https://www.acmicpc.net/problem/1867
# problem type : Graph Theory, Bipartite Matching

# 이분 매칭의 개념만 이해한다면 문제 자체는 간단한 문제

import sys
sys.setrecursionlimit(1000000)
n, k = map(int, sys.stdin.readline().split())

linked = [[] for _ in range(n+1)]
for i in range(k):
    x, y = map(int, sys.stdin.readline().split())
    linked[x].append(y)

def dfs(x):
    global visited, matched
    if visited[x] == 1: return 0
    visited[x] = 1
    for next_node in linked[x]:
        if next_node not in matched or dfs(matched[next_node]): # matched에 next_node가 없거나 matched를 쭉 따라가 봤을 때 next_node가 없을 때
            matched[next_node] = x
            return 1

    return 0

matched = {}
ans = 0
for i in range(1, n+1):
    visited = [0] * (n+1)
    ans += dfs(i)

print(ans)