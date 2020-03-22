# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 13.
# time : 오후 11:34
# problem : https://www.acmicpc.net/problem/1753
# problem type : Dijkstra

# Dijkstra의 정석 같은 문제
# 우선순위 queue 사용할 때는 heapq 사용하자!

import sys
import heapq

V, E = map(int, sys.stdin.readline().split())
start = int(sys.stdin.readline())
linked = [{} for _ in range(V+1)]
for _ in range(E):
    u, v, w = map(int, sys.stdin.readline().split())
    if v in linked[u]:
        linked[u][v] = min(linked[u][v], w) # 최소값으로 업데이트
    else:
        linked[u][v] = w

visited = [False] * (V+1)
distance = [987654321] * (V+1) # distance를 무한대로 설정
que = []

visited[start] = True
distance[start] = 0
heapq.heappush(que, (0, start)) # distance와 index를 함께 넣어줌

while len(que) > 0:
    dis, x = heapq.heappop(que)
    visited[x] = True
    for node in linked[x]:
        if visited[node]: continue
        if distance[x] + linked[x][node] < distance[node]: # start에서 x까지 거리인 distance[x]와 x에서 node까지 바로 이어진 거리를 더한 값이 지금까지 구한 distance[node]보다 작으면 업데이트
            distance[node] = linked[x][node] + distance[x]
            heapq.heappush(que, (distance[node], node))

for i in range(1, V+1):
    if distance[i] == 987654321: print('INF')
    else: print(distance[i])