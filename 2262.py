# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 20.
# time : 오후 7:36
# problem : https://www.acmicpc.net/problem/2262
# problem type : DP

# 조건이 상당히 까다로웠던 문제

import sys
n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
dp = [[987654321] * (n+1) for _ in range(n+1)] # dp[diff][j] : j에서 시작해서 diff만큼 떨어져 있는 선수까지 토너먼트 했을 때 랭킹 차이
rank = [[987654321] * (n+1) for _ in range(n+1)] # rank[diff][j] : j에서 시작해서 diff만큼 떨어져 있는 선수까지 토너먼트 했을 때 1등
for i in range(n):
    dp[0][i] = 0 # i 하나만 뽑는 경우 : 랭킹 차이 0
    rank[0][i] = arr[i] # i 하나만 뽑는 경우 : 랭크는 i의 랭크
    if i+1 < n:
        dp[1][i] = abs(arr[i] - arr[i+1]) # i와 i+1을 뽑는 경우는 랭킹 차이는 그 둘의 차의 절대값
        rank[1][i] = min(arr[i], arr[i+1]) # 랭킹은 i와 i+1 중에 작은 값

for diff in range(2, n): # 토너먼트의 범위
    for j in range(0, n-diff+1): # 시작점의 위치
        for k in range(0, diff): # 토너먼트를 분할하는 위치
            if dp[k][j] + dp[diff-(k+1)][j+k+1] + abs(rank[k][j] - rank[diff-(k+1)][j+k+1]) < dp[diff][j]: # j~j+k까지와 j+(k+1)~j+diff까지로 분할했을 때 각각의 토너먼트 합 + 준우승자와 우승자의 차이 업데으트
                rank[diff][j] = min(rank[k][j], rank[diff-(k+1)][j+k+1]) # 랭킹은 더 작은 값이 올라감
                dp[diff][j] = dp[k][j] + dp[diff - (k + 1)][j + k + 1] + abs(rank[k][j] - rank[diff-(k+1)][j+k+1]) # dp는 부분 문제의 합과 우승자와 준우승자 차이 저장

print(dp[n-1][0])