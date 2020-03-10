# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 10.
# time : 오후 7:42
# problem : https://www.acmicpc.net/problem/1939
# problem type : Binary Search, BFS

# BFS와 Binary Search를 조합해야 하는 문제
# 중량의 최댓값을 Binary Search로 찾아보고, 그 값이 가능한지 BFS를 돌려서 확인

import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
linked = [{} for _ in range(n+1)]
cost_dict = {}

low, high = 9876543210, -1

for i in range(m):
    x, y, c = map(int, sys.stdin.readline().split())

    if y in linked[x]: linked[x][y] = max(linked[x][y], c) # 이미 값이 있으면 제일 큰 값을 넣는다.
    else: linked[x][y] = c

    if x in linked[y]: linked[y][x] = max(linked[y][x], c) # 이미 값이 있으면 제일 큰 값을 넣는다.
    else: linked[y][x] = c

    low = min(low, c)
    high = max(high, c)

start, end = map(int, sys.stdin.readline().split())


def bfs(cost):
    visited = [0 for _ in range(n+1)]
    deq = deque()

    deq.appendleft(start)
    visited[start] = 9876543210
    while len(deq) > 0:
        x = deq.pop()
        for next_node in linked[x]:
            next_cost = linked[x][next_node]

            if visited[next_node] != 0: # 이미 방문한 노드이면 이 노드까지 오는 경로 중 최소값으로 업데이트
                visited[next_node] = min(visited[next_node], visited[x])
                continue
            if next_cost < cost: continue

            deq.appendleft(next_node)
            visited[next_node] = min(next_cost, visited[x]) # x까지 오는 것과 x에서 next_node로 오는 것 중 작은 값을 대입
    return visited[end]

ans = 0
while low <= high:
    mid = (low + high) // 2
    result = bfs(mid) # 가능한 중량 리턴
    if result > ans: # 가능한 중량이 더 크다면 더 큰 mid에서 시도
        ans = result
        low = mid + 1
    else: # 중량이 더 작으면 더 작은 mid에서 시도
        high = mid - 1

print(ans)