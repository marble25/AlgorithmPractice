# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 14.
# time : 오전 10:22
# problem : https://www.acmicpc.net/problem/1261
# problem type : Dijkstra, BFS

# 다익스트라 알고리즘과 BFS를 결합해서 푸는 문제

import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
mirror = []
for _ in range(m):
    mirror.append(sys.stdin.readline().strip())

distance = [[987654321] * (n+1) for _ in range(m+1)]
deq = deque()

dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]

deq.appendleft((0, 0))
distance[0][0] = 0

while len(deq) > 0:
    x, y = deq.pop()
    for i in range(4):
        moved_x = x + dx[i]
        moved_y = y + dy[i]

        if moved_x < 0 or moved_x >= m: continue
        if moved_y < 0 or moved_y >= n: continue

        if mirror[moved_x][moved_y] == '0': # 뚫려있다면 그 값 그대로 넣음
            if distance[moved_x][moved_y] > distance[x][y]:
                distance[moved_x][moved_y] = distance[x][y]
                deq.appendleft((moved_x, moved_y))

        if mirror[moved_x][moved_y] == '1': # 막혀있다면 +1한 값 넣음
            if distance[moved_x][moved_y] > distance[x][y] + 1:
                distance[moved_x][moved_y] = distance[x][y] + 1
                deq.appendleft((moved_x, moved_y))

print(distance[m-1][n-1])