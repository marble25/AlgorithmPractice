# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 8.
# time : 오후 12:30
# problem : https://www.acmicpc.net/problem/10026
# problem type : BFS

# 간단한 BFS 문제

from collections import deque

n = int(input())
arr = []
visited = [[0] * n for _ in range(n)]
for i in range(n):
    input_str = input().strip()
    arr.append([])
    for j in range(n):
        if input_str[j] == 'R':
            arr[i].append(3)
        elif input_str[j] == 'G':
            arr[i].append(2)
        elif input_str[j] == 'B':
            arr[i].append(1)

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(start_x, start_y):
    global visited

    deq = deque()
    deq.appendleft([start_x, start_y])
    visited[start_x][start_y] = 1
    while len(deq) > 0:
        x, y = deq.pop()
        for i in range(4):
            moved_x, moved_y = x+dx[i], y+dy[i]

            if moved_x < 0 or moved_x >= n: continue
            if moved_y < 0 or moved_y >= n: continue

            if visited[moved_x][moved_y] == 0 and arr[moved_x][moved_y] == arr[start_x][start_y]:
                deq.appendleft([moved_x, moved_y])
                visited[moved_x][moved_y] = 1

# 정상인 사람 수 세기
normal_count = 0
for i in range(n):
    for j in range(n):
        if visited[i][j] == 0:
            normal_count += 1
            bfs(i, j)

# 적색을 녹색으로 바꿔주고, visited도 초기화
for i in range(n):
    for j in range(n):
        visited[i][j] = 0
        if arr[i][j] == 3:
            arr[i][j] = 2

# 적녹색약 사람 수 세기
abnormal_count = 0
for i in range(n):
    for j in range(n):
        if visited[i][j] == 0:
            abnormal_count += 1
            bfs(i, j)

print(normal_count, abnormal_count)