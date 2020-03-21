# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 21.
# time : 오전 10:39
# problem : https://www.acmicpc.net/problem/1633
# problem type : DP

# 깔끔하게 클리어한 문제

import sys

arr = []
while True:
    input_ = sys.stdin.readline().strip()
    if input_ == '':
        break
    arr.append(list(map(int, input_.split())))

dp = [[[-1] * 16 for _ in range(16)] for __ in range(1001)] # dp[stage][i][j] : stage를 검사할 때 흑팀을 i명, 백팀을 j명 뽑았을 경우 최대 능력치
dp[0][1][0] = arr[0][0] # 흑팀 1명 뽑기
dp[0][0][1] = arr[0][1] # 백팀 1명 뽑기
dp[0][0][0] = 0 # 안뽑기
for stage in range(len(arr)-1):
    for i in range(16):
        for j in range(16):
            if i+1 < 16 and dp[stage][i][j] != -1: dp[stage+1][i+1][j] = max(dp[stage+1][i+1][j], dp[stage][i][j] + arr[stage+1][0]) # 기존 값과 stage, i, j 상태에서 stage+1을 흑으로 뽑는 것 비교해서 업데이트
            if j+1 < 16 and dp[stage][i][j] != -1: dp[stage+1][i][j+1] = max(dp[stage+1][i][j+1], dp[stage][i][j] + arr[stage+1][1]) # 기존 값과 stage, i, j 상태에서 stage+1을 백으로 뽑는 것 비교해서 업데이트
            if dp[stage][i][j] != -1: dp[stage+1][i][j] = max(dp[stage+1][i][j], dp[stage][i][j]) # 기존 값과 stage, i, j 상태에서 안뽑고 지나가는 것 비교해서 업데이트

print(dp[len(arr)-1][15][15])