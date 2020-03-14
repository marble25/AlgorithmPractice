# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 14.
# time : 오전 12:27
# problem : https://www.acmicpc.net/problem/1916
# problem type : Dijkstra

# Dijkstra의 정석 같은 문제

import sys
import heapq
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
linked = [{} for _ in range(n+1)]
for _ in range(m):
    u, v, w = map(int, sys.stdin.readline().split())
    if v in linked[u]:
        linked[u][v] = min(linked[u][v], w)
    else:
        linked[u][v] = w

start, end = map(int, sys.stdin.readline().split())

visited = [False] * (n+1)
distance = [987654321] * (n+1)
que = []

distance[start] = 0
heapq.heappush(que, (0, start))

while len(que) > 0:
    dis, x = heapq.heappop(que)
    visited[x] = True
    for next_node in linked[x]:
        if visited[next_node]: continue
        if distance[x] + linked[x][next_node] < distance[next_node]:
            distance[next_node] = distance[x] + linked[x][next_node]
            heapq.heappush(que, (distance[next_node], next_node))

print(distance[end])