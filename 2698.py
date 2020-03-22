# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 28.
# time : 오후 9:19
# problem : https://www.acmicpc.net/problem/2698
# problem type : DP

# Dynamic Table 짜느라 힘들었던 문제
# 종이에 완전탐색을 일일히 한 후 점화식 유도해서 풂

import sys

# dp[n][k][l] = n개의 수열의 마지막 자리가 l(0 또는 1)일 때 인접한 비트수가 k인 가짓수
dp = [[[0] * 2 for _ in range(101)] for __ in range(101)]
dp[0][0][0] = 1
for i in range(1, 101):
    for j in range(0, 101):
        dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1]
        dp[i][j][1] = (dp[i-1][j-1][1] if j-1 >= 0 else 0) + dp[i-1][j][0]

T = int(sys.stdin.readline())
for i in range(T):
    n, k = map(int, sys.stdin.readline().split())
    print(dp[n][k][0] + dp[n][k][1]) # 0인 경우와 1인 경우의 합