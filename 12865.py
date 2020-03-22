# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 19.
# time : 오후 5:44
# problem : https://www.acmicpc.net/problem/12865
# problem type : DP

# 기초적인 0/1 배낭 문제

import sys
n, k = map(int, sys.stdin.readline().split())
arr = [(0, 0)]
for i in range(n):
    w, v = map(int, sys.stdin.readline().split())
    arr.append((w, v))

dp = [[0] * (k+1) for _ in range(n+1)]
for i in range(1, n+1):
    for j in range(k+1):
        if j >= arr[i][0]: # 무게가 i물품 무게보다 크면
            dp[i][j] = max(dp[i-1][j-arr[i][0]] + arr[i][1], dp[i-1][j]) # i번째 물품을 쓰지 않고 j 무게를 채운 것과 i물품을 사용한 것 중 최대를 저장
        else: # 무게가 i물품 무게보다 작으면 이전 값 그대로 저장
            dp[i][j] = dp[i-1][j]

result = -1
for i in range(k+1): # 최대 k무게 중 최대 value를 찾음
    result = max(result, dp[n][i])

print(result)