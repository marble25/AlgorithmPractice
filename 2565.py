# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 19.
# time : 오후 12:56
# problem : https://www.acmicpc.net/problem/2565
# problem type : DP, LIS

# 간단한 LIS 문제

import sys

n = int(sys.stdin.readline())
arr = []
for i in range(n):
    x, y = map(int, sys.stdin.readline().split())
    arr.append((x, y))

arr.sort()
dp = [0] * n
result = -1
for i in range(n):
    max_index = -1
    max_val = -1
    for j in range(i):
        if arr[j][1] < arr[i][1] and dp[j] > max_val: # 겹치지 않고 max_val보다 dp값이 클 때 dp값으로 max_val 업데이트
            max_val = dp[j]
            max_index = j

    if max_index == -1: # LIS가 없으면 새로 시작
        dp[i] = 1
    else: # LIS가 있으면 dp는 최대 LIS 길이 + 1
        dp[i] = dp[max_index] + 1

    result = max(result, dp[i]) # 최대 LIS 길이 저장

print(n-result)