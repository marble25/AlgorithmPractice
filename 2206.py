# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 8.
# time : 오후 4:03
# problem : https://www.acmicpc.net/problem/2206
# problem type : BFS

# 벽을 부섰는지 상태까지 같이 저장하는 방법으로 간단히 풀리는 문제

import sys
from collections import deque
n, m = map(int, sys.stdin.readline().split())

# input을 int형식으로 바꿔줌
arr = [[0] * (m) for _ in range(n)]
for i in range(n):
    input_str = sys.stdin.readline().strip()
    for j in range(m):
        arr[i][j] = 1 if input_str[j] == '1' else 0

# n이 1이고, m이 1인 경우를 따로 처리
if n == 1 and m == 1:
    print(1)
    sys.exit(0)

# visited[i][j][k] : k가 0이면 벽을 한번도 안부순 거고, k가 1이면 벽을 한번 이미 부순 상태. i, j를 방문한 적 있는지 체크하는 배열
visited = [[[0] * 2 for _ in range(m)] for __ in range(n)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

deq = deque()
deq.appendleft((0, 0, 0))
visited[0][0][0] = 1
while len(deq) > 0:
    x, y, count = deq.pop()
    for i in range(4):
        moved_x, moved_y = x + dx[i], y + dy[i]

        # 배열 밖으로 벗어나는지 체크
        if moved_x < 0 or moved_x >= n: continue
        if moved_y < 0 or moved_y >= m: continue

        if arr[moved_x][moved_y] == 0 and visited[moved_x][moved_y][count] == 0: # 벽 안부수고 갈 수 있다면
            visited[moved_x][moved_y][count] = visited[x][y][count] + 1
            deq.appendleft((moved_x, moved_y, count))
        elif arr[moved_x][moved_y] == 1 and count == 0 and visited[moved_x][moved_y][1] == 0: # 다음 칸이 막혀있고 벽을 부술 수 있는 상태라면
            visited[moved_x][moved_y][1] = visited[x][y][0] + 1
            deq.appendleft((moved_x, moved_y, 1))

if visited[n-1][m-1][0] == 0 and visited[n-1][m-1][1] == 0: # 도달할 수 없으면 -1 출력
    print(-1)
else:
    if visited[n-1][m-1][0] == 0:
        print(visited[n-1][m-1][1])
    elif visited[n-1][m-1][1] == 0:
        print(visited[n-1][m-1][0])
    else:
        print(min(visited[n-1][m-1][0], visited[n-1][m-1][1]))