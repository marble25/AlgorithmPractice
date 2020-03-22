# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 8.
# time : 오전 10:53
# problem : https://www.acmicpc.net/problem/7569
# problem type : BFS

# sys.exit(0)이 아니라 exit(0)을 써서 여러번 틀린 문제

import sys
from collections import deque
M, N, H = map(int, sys.stdin.readline().split())

box = [[[0] * 105 for _ in range(105)] for __ in range(105)]
deq = deque()

dx = [0, 0, 0, 0, 1, -1]
dy = [0, 0, 1, -1, 0, 0]
dz = [1, -1, 0, 0, 0, 0]

for k in range(H):
    for j in range(N):
        input_line = list(map(int, sys.stdin.readline().split()))
        for i in range(M):
            box[k][j][i] = input_line[i]
            if box[k][j][i] == 1: # 토마토가 익었으면 큐에 저장
                deq.appendleft([k, j, i])

while len(deq) > 0:
    x, y, z = deq.pop()
    for i in range(6):
        target_x = x + dx[i]
        target_y = y + dy[i]
        target_z = z + dz[i]

        # 목표 x, y, z가 배열 밖이면 continue
        if target_x < 0 or target_x >= H: continue
        if target_y < 0 or target_y >= N: continue
        if target_z < 0 or target_z >= M: continue

        # 방문 안한 곳이면 이전 일수에 + 1하고, 큐에 넣음
        if box[target_x][target_y][target_z] == 0:
            box[target_x][target_y][target_z] = box[x][y][z] + 1
            deq.appendleft([target_x, target_y, target_z])

max_val = -1
for k in range(H):
    for j in range(N):
        for i in range(M):
            if box[k][j][i] == 0: # 안익은 토마토가 있으면 -1 출력
                print(-1)
                sys.exit(0)

            max_val = max(max_val, box[k][j][i])

print(max_val-1)