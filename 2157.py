# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 5.
# time : 오후 1:50
# problem : https://www.acmicpc.net/problem/2157
# problem type : DP

# 전형적인 DP 문제

import sys
sys.setrecursionlimit(100000)
n, m, k = map(int, sys.stdin.readline().split())

table = [[0] * (n+1) for _ in range(n+1)]
for i in range(k):
    a, b, c = map(int, sys.stdin.readline().split())
    if a > b: continue # 반대로 가는 경로는 패스
    table[a][b] = max(table[a][b], c) # 기내식 점수 중 max값만 저장

# dp[i][j] : i번의 항해로 j도시까지 오는 기내식 점수 총합 max
dp = [[-1] * (n+1) for _ in range(m+1)]

def dfs(stage, city):
    global n, m
    global table, dp
    if stage == m: return -987654321 # m개 초과 도시를 지나면 안됨
    if city == n: return 0 # 마지막 도시에 도달한다면 0 리턴
    if dp[stage][city] != -1: return dp[stage][city] # dp값 있으면 바로 리턴

    for next_city in range(city+1, n+1):
        if table[city][next_city] != 0:
            dp[stage][city] = max(dp[stage][city], dfs(stage+1, next_city) + table[city][next_city]) # 현재 dp값과 다음 도시와의 기내식 점수 + 다음 도시부터 끝까지 dfs 리턴값 중 큰 값을 dp에 넣음

    return dp[stage][city]

print(dfs(0, 1))