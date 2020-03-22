# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 14.
# time : 오후 9:42
# problem : https://www.acmicpc.net/problem/5719
# problem type : BFS, Graph Theory, Dijkstra

# 다익스트라를 두번 돌리면 충분히 맞을 수 있는 문제
# 다익스트라 처음 돌릴 때 부모 노드 저장 -> 부모 노드 따라가면서 최솟값 나오는 경로 삭제 -> 다시 다익스트라 돌려서 거의 최단 경로 길이 출력

def dijkstra(start, end):
    global parent

    distance = [987654321] * (n + 1)
    visited = [False] * (n+1)
    que = []

    distance[start] = 0
    heapq.heappush(que, (0, start))
    visited[start] = True

    while len(que) > 0:
        dis, x = heapq.heappop(que)
        visited[x] = True
        for next_node in linked[x]:
            if visited[next_node]: continue
            if distance[x] + linked[x][next_node] < distance[next_node]: # 비용이 최소이면 부모를 x로 세팅하고 distance 업데이트
                distance[next_node] = distance[x] + linked[x][next_node]
                parent[next_node] = [x]
                heapq.heappush(que, (distance[next_node], next_node))
            elif distance[x] + linked[x][next_node] == distance[next_node]: # 비용이 같은 경로가 나오면 부모를 추가
                parent[next_node].append(x)
    return distance[end]
def del_path(index, start):
    global linked

    if index == start: return
    for prev_node in parent[index]:
        linked[prev_node].pop(index, None) # 간선 삭제
        del_path(prev_node, start) # 부모 노드로 재귀


import sys
import heapq

sys.setrecursionlimit(1000000)

while True:
    n, m = map(int, sys.stdin.readline().split())
    if n == m == 0: break

    s, d = map(int, sys.stdin.readline().split())

    linked = [{} for _ in range(n+1)]
    for i in range(m):
        u, v, w = map(int, sys.stdin.readline().split())
        linked[u][v] = w

    parent = [[] for _ in range(n+1)]
    result = dijkstra(s, d)
    del_path(d, s)
    result = dijkstra(s, d)
    print(result if result != 987654321 else -1) # 경로가 없으면 -1 출력, 아니면 result 출력