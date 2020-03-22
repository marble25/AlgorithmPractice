# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 8.
# time : 오후 12:45
# problem : https://www.acmicpc.net/problem/13460
# problem type : BFS

# 수많은 예저 넣느라 눈 빠지는줄 알았음
# 문제 자체는 간단하나 처리할 조건들이 너무 많아 까다롭다

import sys
from collections import deque
n, m = map(int, sys.stdin.readline().split())

board = []
visited = [[[[0] * 11 for _ in range(11)] for __ in range(11)] for ___ in range(11)] # red의 x, y좌표, blue의 x, y좌표 순으로 넣는다.
particle = '.#ORB'

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

blue_start = None
red_start = None

# input을 받아 숫자 배열로 변환
for i in range(n):
    input_str = sys.stdin.readline().strip()
    board.append([])
    for j in range(m):
        for k in range(5):
            if input_str[j] == particle[k]:
                board[i].append(k)
                if k == 3: red_start = (i, j)
                elif k == 4: blue_start = (i, j)
                break

# queue에 넣는 값 : (red x, red y), (blue x, blue y), count
deq = deque()
deq.appendleft([red_start, blue_start, 0])
while len(deq) > 0:
    (red_x, red_y), (blue_x, blue_y), try_count = deq.pop()
    visited[red_x][red_y][blue_x][blue_y] = 1
    if try_count > 9: # 10번 넘게 움직인다면 -1 출력
        print(-1)
        sys.exit(0)
    original_values = [red_x, red_y, blue_x, blue_y] # 초기값을 따로 저장
    for i in range(4):
        is_blue_in_a_way = False
        is_red_in_a_way = False

        is_blue_goal = False

        red_x, red_y, blue_x, blue_y = original_values # red와 blue의 좌표를 원래 위치로 초기화

        while True:
            blue_x += dx[i]
            blue_y += dy[i]

            if board[blue_x][blue_y] == 1: # 벽이면 벽 전까지
                blue_x -= dx[i]
                blue_y -= dy[i]
                break
            elif board[blue_x][blue_y] == 2: # 가는 길에 구멍이 있으면
                is_blue_goal = True
                break
            elif blue_x == original_values[0] and blue_y == original_values[1]: # 가는 길에 red가 있으면
                is_red_in_a_way = True

        if is_red_in_a_way: # red 전칸에 맘춤
            blue_x -= dx[i]
            blue_y -= dy[i]

        if is_blue_goal: # blue가 골인하면 이 경우는 실패한 경우
            continue

        count = 0
        while True:
            red_x += dx[i]
            red_y += dy[i]

            count += 1
            if board[red_x][red_y] == 1: # 벽이면 벽 전까지
                red_x -= dx[i]
                red_y -= dy[i]
                break
            elif board[red_x][red_y] == 2: # 가는 길에 구멍이 있으면 blue가 red 앞에 있지 않다면 구멍을 통해 빼낼 수 있음
                if not is_blue_in_a_way:
                    print(try_count + 1)
                    sys.exit(0)
                break
            elif original_values[2] == red_x and original_values[3] == red_y: # 가는 길에 blue가 있으면
                is_blue_in_a_way = True

        if is_blue_in_a_way: # blue 전칸에 멈춤
            red_x -= dx[i]
            red_y -= dy[i]

        if visited[red_x][red_y][blue_x][blue_y] == 0: # 이미 왔던 곳이 아니면 새로 추가
            deq.appendleft([(red_x, red_y), (blue_x, blue_y), try_count+1])

print(-1)