# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 9.
# time : 오전 12:20
# problem : https://www.acmicpc.net/problem/1103
# problem type : DP, BFS

# 다들 dfs로 풀었다는데 bfs로도 충분히 가능한 문제
from collections import deque
import sys
sys.setrecursionlimit(1000000)

n, m = map(int, sys.stdin.readline().split())
arr = [[0] * m for _ in range(n)]
for i in range(n):
    input_str = sys.stdin.readline().strip()
    for j in range(m):
        arr[i][j] = ord(input_str[j]) - ord('0')

dp = [[0] * m for _ in range(n)]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

deq = deque()
deq.appendleft((0, 0))
dp[0][0] = 1
while len(deq) > 0:
    x, y = deq.pop()
    if dp[x][y] > n * m: # n*m보다 크다는 얘기는 최소한 모든 칸을 다 돈 이후이므로 무한번 움직일 수 있는 경우다.
        print(-1)
        sys.exit(0)
    for i in range(4):
        moved_x = x + dx[i] * arr[x][y]
        moved_y = y + dy[i] * arr[x][y]

        if moved_x < 0 or moved_x >= n: continue # 세로로 벗어나느 경우 제외
        if moved_y < 0 or moved_y >= m: continue # 가로로 벗어나는 경우 제외
        if arr[moved_x][moved_y] == 24: continue # 구멍인 경우 제외
        if dp[moved_x][moved_y] == dp[x][y] + 1: continue # 같은 깊이를 여러번 탐색하는 것을 막음 ( 중요 )

        dp[moved_x][moved_y] = max(dp[moved_x][moved_y], dp[x][y] + 1) # x, y를 탐색하는데 든 횟수에 1을 더한 값을 저장
        deq.appendleft((moved_x, moved_y))

max_val = -1
for i in range(n):
    for j in range(m):
        max_val = max(dp[i][j], max_val)

print(max_val)