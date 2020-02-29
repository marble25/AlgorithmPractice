# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 29.
# time : 오후 9:02
# problem : https://www.acmicpc.net/problem/2718
# problem type : DP

import sys

dp = [0] * 100000
dp[0] = 1
dp[1] = 1
dp[2] = 5
for i in range(3, 100000):
    dp[i] = dp[i-1] + 4 * dp[i-2]

T = int(sys.stdin.readline())
for _ in range(T):
    n = int(sys.stdin.readline())
    print(dp[n])