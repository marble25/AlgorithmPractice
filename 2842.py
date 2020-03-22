# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 16.
# time : 오후 7:20
# problem : https://www.acmicpc.net/problem/2842
# problem type : Binary Search, Two pointer

# Two pointer 개념을 생각해 보았을 때 bfs로 가능한지 의문이었는데 생각해 보니 충분히 가능한 문제
# Test data 많이 넣어 보다가 오류를 찾아 해결

import sys
from collections import deque

n = int(sys.stdin.readline())
village_map = []
start = None
k_count = 0
for i in range(n):
    village_map.append(sys.stdin.readline().strip())
    for j in range(n):
        if village_map[i][j] == 'P':
            start = (i, j)
        elif village_map[i][j] == 'K':
            k_count += 1

heights_map = []
heights = {}
for i in range(n):
    heights_map.append(list(map(int, sys.stdin.readline().split())))
    for j in range(n):
        heights[heights_map[i][j]] = 1

heights = list(heights.keys())
heights.sort()
result = 10 ** 8

low = 0
high = 0
while low < len(heights) and high < len(heights):
    if heights_map[start[0]][start[1]] < heights[low] or heights_map[start[0]][start[1]] > heights[high]: # 처음 위치가 범위에 들어가지 않으면 high 증가하고 continue
        high += 1
        continue

    visited = [[False] * (n+1) for _ in range(n+1)]
    que = deque()

    visited[start[0]][start[1]] = True
    que.appendleft(start)

    count = 0

    while len(que) > 0:
        x, y = que.pop()

        dx = [-1, -1, -1, 0, 0, 1, 1, 1]
        dy = [-1, 0, 1, -1, 1, -1, 0, 1]

        for i in range(8):
            moved_x = x + dx[i]
            moved_y = y + dy[i]
            if moved_x < 0 or moved_x >= n: continue
            if moved_y < 0 or moved_y >= n: continue
            if visited[moved_x][moved_y]: continue
            if heights_map[moved_x][moved_y] < heights[low] or heights_map[moved_x][moved_y] > heights[high]: continue # 움직일 곳이 범위에 해당하지 않으면 continue
            if village_map[moved_x][moved_y] == 'K': count += 1 # 움직일 곳이 배달할 곳이면 count 증가
            visited[moved_x][moved_y] = True
            que.appendleft((moved_x, moved_y))

    if count == k_count: # count가 k갯수와 같으면 low를 증가시킨 후에 다시 도전
        result = min(result, heights[high] - heights[low])
        low += 1
    else: # 아니면 high 증가해서 범위를 더 늘려줌
        high += 1

print(result)