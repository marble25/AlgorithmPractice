# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 16.
# time : 오후 11:39
# problem : https://www.acmicpc.net/problem/1987
# problem type : Backtracking

# visited를 맵이 아닌 배열로 바꾸니까 맞았던 문제
# 맵도 find 함수 O(1)이던데..
# 아니면 del 함수 때문이었나?
# 약간의 시간 단축도 중요하다는 것을 알려줌제

def dfs(x, y, visited, stage):
    global max_stage
    max_stage = max(max_stage, stage)

    for i in range(4):
        moved_x = x + dx[i]
        moved_y = y + dy[i]

        if moved_x < 0 or moved_x >= r: continue
        if moved_y < 0 or moved_y >= c: continue

        alphabet = board[moved_x][moved_y]
        if visited[alphabet] == 1: continue # 이미 방문한 알파벳이면 continue

        visited[alphabet] = 1 # 방문한 알파벳 체크
        dfs(moved_x, moved_y, visited, stage+1)
        visited[alphabet] = 0 # 방문했던 알파벳 해

import sys
sys.setrecursionlimit(10 * 7)

r, c = map(int, sys.stdin.readline().split())
board = [[0] * c for _ in range(r)]
for i in range(r):
    input_line = sys.stdin.readline().strip()
    for j in range(c):
        board[i][j] = ord(input_line[j]) - ord('A')

max_stage = 0
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

visited = [0] * 26
visited[board[0][0]] = 1
dfs(0, 0, visited, 1)
print(max_stage)