# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 8.
# time : 오후 11:23
# problem : https://www.acmicpc.net/problem/2579
# problem type : DP

# 간단한 DP 문제
import sys

n = int(input())
arr = []
for i in range(n):
    arr.append(int(input()))

# dp[i][0] : 이전 계단이 i-2인 경우
# dp[i][1] : i-1번째 계단을 밟고 온 경우
dp = [[0] * 2 for _ in range(300)]

# n이 1인 경우와 2인 경우는 따로 처리
if n == 1:
    print(arr[0])
    sys.exit(0)
elif n == 2:
    print(arr[0] + arr[1])
    sys.exit(0)

dp[0][0] = arr[0]
dp[1][1] = arr[0] + arr[1]
dp[1][0] = arr[1]

for i in range(2, n):
    dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + arr[i] # i-2 계단들 중 최댓값과 현재 점수를 더함
    dp[i][1] = dp[i-1][0] + arr[i] # i-1번째 계단과 현재 점수를 더함

print(max(dp[n-1][0], dp[n-1][1]))