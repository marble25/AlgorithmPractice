# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 21.
# time : 오후 11:41
# problem : https://www.acmicpc.net/problem/2159
# problem type : DP

# 깔끔하게 맞춘 문제

import sys
n = int(sys.stdin.readline())
start = list(map(int, sys.stdin.readline().split()))
arr = []
for i in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))

dx = [0, 1, -1, 0, 0]
dy = [0, 0, 0, -1, 1]

# 순서대로 그 위치, 상, 하, 좌, 우
dp = [[999987654321] * 5 for _ in range(n+1)]
for i in range(5):
    if arr[0][0] + dx[i] < 0 or arr[0][0] + dx[i] >= 100000: continue # x 범위 필터링
    if arr[0][1] + dy[i] < 0 or arr[0][1] + dy[i] >= 100000: continue # y 범위 필터링
    dp[0][i] = abs(start[0] - (arr[0][0] + dx[i])) + abs(start[1] - (arr[0][1] + dy[i])) # start에서 그 위치, 상하좌우 까지의 위치를 저장함

for i in range(1, n):
    for j in range(5):
        if arr[i][0] + dx[j] < 0 or arr[i][0] + dx[j] >= 100000: continue
        if arr[i][1] + dy[j] < 0 or arr[i][1] + dy[j] >= 100000: continue

        for k in range(5):
            if arr[i-1][0] + dx[k] < 0 or arr[i-1][0] + dx[k] >= 100000: continue
            if arr[i-1][1] + dy[k] < 0 or arr[i-1][1] + dy[k] >= 100000: continue

            dp[i][j] = min(dp[i-1][k] + abs((arr[i][0] + dx[j]) - (arr[i-1][0] + dx[k])) + abs((arr[i][1] + dy[j]) - (arr[i-1][1] + dy[k])), dp[i][j]) # 그 위치, 상하좌우 위치에서 다음 위치, 상하좌우 위치까지 거리 중 최소를 저장

min_val = 999987654321
for i in range(5):
    min_val = min(min_val, dp[n-1][i])

print(min_val)