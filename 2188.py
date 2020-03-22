# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 9.
# time : 오후 10:01
# problem : https://www.acmicpc.net/problem/2188
# problem type : Bipartite Matching

# 간단한 이분 매칭 문제
import sys
sys.setrecursionlimit(1000000)

N, M = map(int, sys.stdin.readline().split())

linked = [[] for _ in range(N+1)]
for i in range(1, N+1):
    input_line = list(map(int, sys.stdin.readline().split()))
    size_of_wanted_room = input_line[0]
    for j in range(size_of_wanted_room):
        linked[i].append(input_line[j+1])

def dfs(x):
    global visited, matched
    if visited[x]: return 0
    visited[x] = True
    for next_node in linked[x]:
        if not next_node in matched or dfs(matched[next_node]) == 1:
            matched[next_node] = x
            return 1
    return 0

matched = {}
for i in range(1, N+1):
    visited = [False for _ in range(N+1)]
    dfs(i)

print(len(matched)) # 매칭된 축사수 출력