# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 5.
# time : 오후 2:09
# problem : https://www.acmicpc.net/problem/2229
# problem type : DP

import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

dp = [0]

for i in range(n):
    max_val, min_val = -1, 987654321
    re = 0
    for j in range(i, -1, -1): # 0~j까지 dp 최댓값과 j+1 ~ i까지 그룹핑(새로운 그룹)한 것 중 최댓값을 저장
        max_val = max(arr[j], max_val)
        min_val = min(arr[j], min_val)
        re = max(re, dp[j]+max_val-min_val)
    dp.append(re)

print(dp[n])