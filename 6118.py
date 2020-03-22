# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 15.
# time : 오후 3:27
# problem : https://www.acmicpc.net/problem/6118
# problem type : Dijkstra, BFS, Graph Theory

# Dijkstra를 연습하느라 Dijkstra로 풀었으나, BFS로도 충분히 풀리는 문제

def dijkstra():
    distance = [987654321] * (n+1)
    que = []
    visited = [False] * (n+1)

    distance[1] = 0
    heapq.heappush(que, (0, 1))
    visited[1] = True

    while len(que) > 0:
        dis, x = heapq.heappop(que)
        for next_node in linked[x]:
            if visited[next_node]: continue
            if distance[next_node] > distance[x] + 1: # 정점 사이 거리는 항상 1이기 때문에 1 더해진 것과 비교
                distance[next_node] = distance[x] + 1
                heapq.heappush(que, (distance[next_node], next_node))

    # 최대가 되는 정점 찾기
    max_val = -1
    max_index = 0
    max_count = 0
    for i in range(1, n+1):
        if distance[i] != 987654321 and distance[i] > max_val:
            max_val = distance[i]
            max_index = i
            max_count = 1
        elif distance[i] == max_val:
            max_count += 1

    print(max_index, max_val, max_count)

import sys
import heapq
n, m = map(int, sys.stdin.readline().split())
linked = [[] for _ in range(n+1)]
for _ in range(m):
    x, y = map(int, sys.stdin.readline().split())
    linked[x].append(y)
    linked[y].append(x)

dijkstra()
