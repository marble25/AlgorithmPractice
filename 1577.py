# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 20.
# time : 오후 11:00
# problem : https://www.acmicpc.net/problem/1577
# problem type : DP

# 굉장히 간단한 문제

import sys
n, m = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())

construct = dict()
for i in range(k):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    x1, x2 = min(x1, x2), max(x1, x2)
    y1, y2 = min(y1, y2), max(y1, y2)
    construct[(y1, x1, y2, x2)] = 1 # 공사중인 도로를 dict에 넣어줌

dp = [[0] * (n+1) for _ in range(m+1)]
dp[0][0] = 1
for i in range(1, m+1):
    if (i-1, 0, i, 0) not in construct: # 공사중이 아니라면 이전 경로를 가져옴
        dp[i][0] = dp[i-1][0]

for i in range(1, n+1):
    if (0, i-1, 0, i) not in construct: # 공사중이 아니라면 이전 경로를 가져옴
        dp[0][i] = dp[0][i-1]

for i in range(1, m+1):
    for j in range(1, n+1):
        if (i-1, j, i, j) not in construct:
            dp[i][j] += dp[i-1][j] # 밑에서 오는 경우 +
        if (i, j-1, i, j) not in construct:
            dp[i][j] += dp[i][j-1] # 왼쪽에서 오는 경우 +

print(dp[m][n]) # 모든 경우