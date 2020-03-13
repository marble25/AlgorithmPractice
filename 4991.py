# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 13.
# time : 오후 8:29
# problem : https://www.acmicpc.net/problem/4991
# problem type : BFS

# 제발 실수 하지 말자..
# linked 체크를 안해주는 것은 웬말이냐..

# 청소기 시작 위치를 포함한 먼지들 끼리의 거리를 구함
def bfs(start_point):
    global linked
    visited = [[0] * (w+1) for _ in range(h+1)]
    visited[start_point[0]][start_point[1]] = 1

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    deq = deque()
    deq.appendleft(start_point)

    start_index = dusts[start_point]
    while len(deq) > 0:
        x, y = deq.pop()
        for i in range(4):
            moved_x = x + dx[i]
            moved_y = y + dy[i]

            if moved_x < 0 or moved_x >= h: continue
            if moved_y < 0 or moved_y >= w: continue
            if arr[moved_x][moved_y] == 'x': continue
            if visited[moved_x][moved_y] != 0: continue

            visited[moved_x][moved_y] = visited[x][y] + 1
            deq.appendleft((moved_x, moved_y))
            if arr[moved_x][moved_y] == '*' or arr[moved_x][moved_y] == 'o':
                dust_index = dusts[(moved_x, moved_y)]
                linked[start_index][dust_index] = visited[moved_x][moved_y] - 1
                linked[dust_index][start_index] = visited[moved_x][moved_y] - 1

def calc_dist(index, stage, cost):
    global checked, min_val
    if stage == len(dusts)-1: # stage가 끝까지 갔을 때 min값 업데이트
        min_val = min(cost, min_val)
        return

    for i in range(len(dusts)):
        if not checked[i] and linked[index][i] != -1: # 처음 방문하는 정점이고 연결이 되어 있을 때
            checked[i] = True
            calc_dist(i, stage+1, cost+linked[index][i]) # cost를 더해줌
            checked[i] = False

import sys
from collections import deque

sys.setrecursionlimit(100000)

while True:
    w, h = map(int, sys.stdin.readline().split())
    if w == h == 0: break

    linked = [[-1] * 12 for _ in range(12)]
    arr = []
    start = ()
    dusts = {}
    for i in range(h):
        arr.append(sys.stdin.readline().strip())
        for j in range(w):
            if arr[i][j] == 'o': # 시작 위치면 start값에 넣음
                start = (i, j)
                dusts[(i, j)] = len(dusts)

            if arr[i][j] == '*':
                dusts[(i, j)] = len(dusts)

    for dust in dusts: # 모든 먼지 위치에 대해 다른 먼지와의 거리를 구함
        bfs(dust)

    checked = [False] * 12
    min_val = 987654321

    start_index = dusts[start] # 청소기 시작 위치에서 시작하도록 순열 설정
    checked[start_index] = True
    calc_dist(start_index, 0, 0) # 모든 경우의 수 탐색

    print(min_val if min_val != 987654321 else -1)