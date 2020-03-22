# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 9.
# time : 오후 11:13
# problem : https://www.acmicpc.net/problem/11375
# problem type : Bipartite Matching

import sys
sys.setrecursionlimit(1000000)
N, M = map(int, sys.stdin.readline().split())

linked = [[] for _ in range(N+1)]
for i in range(1, N+1):
    input_list = list(map(int, sys.stdin.readline().split()))
    input_size = input_list[0]
    for j in range(input_size):
        linked[i].append(input_list[j+1])

def dfs(x):
    global visited, matched
    if visited[x]: return 0
    visited[x] = 1
    for next_node in linked[x]:
        if next_node not in matched or dfs(matched[next_node]) == 1:
            matched[next_node] = x
            return 1
    return 0

matched = {}
for i in range(1, N+1):
    visited = [False for _ in range(N+1)]
    dfs(i)

print(len(matched))