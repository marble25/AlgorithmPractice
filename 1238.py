# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 14.
# time : 오전 10:39
# problem : https://www.acmicpc.net/problem/1238
# problem type : Dijkstra

# 다익스트라를 1번 진행하고 역으로 1번 진행해서 둘의 합이 최대가 되는 값을 출력

def dijkstra(start_point, local_linked):
    global result

    distance = [987654321] * (n + 1)
    visited = [False] * (n + 1)
    que = []

    distance[start_point] = 0
    heapq.heappush(que, (0, start_point))

    while len(que) > 0:
        dis, x = heapq.heappop(que)
        visited[x] = True
        for next_node in local_linked[x]:
            if visited[next_node]: continue

            if distance[x] + local_linked[x][next_node] < distance[next_node]:
                distance[next_node] = distance[x] + local_linked[x][next_node]
                heapq.heappush(que, (distance[next_node], next_node))

    for i in range(1, n + 1):
        result[i] += distance[i]

import sys
import heapq

n, m, start = map(int, sys.stdin.readline().split())
linked = [{} for _ in range(n+1)]
linked_inv = [{} for _ in range(n+1)]
for _ in range(m):
    u, v, w = map(int, sys.stdin.readline().split())
    if v in linked[u]:
        linked[u][v] = min(linked[u][v], w)
    else:
        linked[u][v] = w

    if u in linked_inv[v]:
        linked_inv[v][u] = min(linked_inv[v][u], w)
    else:
        linked_inv[v][u] = w

result = [0] * (n+1)
dijkstra(start, linked)
dijkstra(start, linked_inv)

max_val = -1
for i in range(1, n+1):
    max_val = max(result[i], max_val)

print(max_val)

