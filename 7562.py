# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 8.
# time : 오후 12:00
# problem : https://www.acmicpc.net/problem/7562
# problem type : BFS

# 간단한 BFS 문제

import sys
from collections import deque
T = int(sys.stdin.readline())

dx = [2, 2, 1, 1, -1, -1, -2, -2]
dy = [1, -1, 2, -2, 2, -2, 1, -1]

while T > 0:
    l = int(sys.stdin.readline())
    x, y = map(int, sys.stdin.readline().split())
    target_x, target_y = map(int, sys.stdin.readline().split())

    deq = deque()
    table = [[0] * l for _ in range(l)]

    table[x][y] = 1
    deq.appendleft([x, y])
    while len(deq) > 0:
        x, y = deq.pop()
        for i in range(8):
            moved_x = x + dx[i]
            moved_y = y + dy[i]

            if moved_x < 0 or moved_x >= l: continue
            if moved_y < 0 or moved_y >= l: continue

            if table[moved_x][moved_y] == 0:
                deq.appendleft([moved_x, moved_y])
                table[moved_x][moved_y] = table[x][y] + 1


    print(table[target_x][target_y]-1)
    T -= 1