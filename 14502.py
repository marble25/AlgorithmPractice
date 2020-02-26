# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 26.
# time : 오후 3:41
# problem : https://www.acmicpc.net/problem/14502
# problem type : Brute Force, BFS

import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
original_map = []
max_value = -1
virus_map = [[0] * m for _ in range(n)] # original map의 복사본을 생성

for i in range(n):
    original_map.append(list(map(int, sys.stdin.readline().split())))
    for j in range(m):
        virus_map[i][j] = original_map[i][j]
q = [] # 원래 바이러스인 것의 갯수를 저장할 list 생성(original queue)

for i in range(n):
    for j in range(m):
        if virus_map[i][j] == 2:
            q.append((i, j))

def check_safety_area(n, m, original_map, original_queue):
    global virus_map
    q = deque()
    result = 0

    for i in range(n):
        for j in range(m):
            if original_map[i][j] == 1 or original_map[i][j] == 2: # 빈 방이 아니라면 result 더해줌
                result += 1
            virus_map[i][j] = original_map[i][j]

    # Queue 초기화
    for element in original_queue:
        q.append(element)

    # bfs로 바이러스가 퍼진 곳 탐색
    while len(q) > 0:
        i, j = q.pop()
        if i+1 < n and virus_map[i+1][j] == 0:
            virus_map[i+1][j] = 2
            q.append((i+1, j))
            result += 1

        if j+1 < m and virus_map[i][j+1] == 0:
            virus_map[i][j+1] = 2
            q.append((i, j+1))
            result += 1

        if i-1 >= 0 and virus_map[i-1][j] == 0:
            virus_map[i-1][j] = 2
            q.append((i-1, j))
            result += 1

        if j-1 >= 0 and virus_map[i][j-1] == 0:
            virus_map[i][j-1] = 2
            q.append((i, j-1))
            result += 1

    # 전체 방 갯수에서 0이 아닌 방 갯수 빼기
    return n * m - result


def make_wall(wall_left, n, m, original_map, original_queue):
    global max_value
    if wall_left == 0: # wall_left가 0이 될 때까지 재귀
        max_value = max(max_value, check_safety_area(n, m, original_map, original_queue))
        return
    for i in range(n):
        for j in range(m):
            if original_map[i][j] == 0: #
                original_map[i][j] = 1
                make_wall(wall_left - 1, n, m, original_map, original_queue)
                original_map[i][j] = 0


make_wall(3, n, m, original_map, q)
print(max_value)
