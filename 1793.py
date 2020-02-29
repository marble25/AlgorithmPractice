# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 29.
# time : 오후 4:53
# problem : https://www.acmicpc.net/problem/1793
# problem type : DP

# 어이없게도 dp[0]이 1이어야 한다
import sys

# dp[i] : 2*i 직사각형을 채우는 경우의 수
# dp[i-2]에 2*1 타일을 가로로 2개 놓는 것과 2*2 타일 놓는 것 해서 2를 곱해서 더해줌
# dp[i-1]은 2*1 타일을 세로로 1개 놓는것 해서 더해줌
dp = [0] * 260
dp[0] = 1
dp[1] = 1
dp[2] = 3
for i in range(3, 251):
    dp[i] = dp[i-1] + 2 * dp[i-2]

for n in map(int, sys.stdin.read().split()):
    print(dp[n])