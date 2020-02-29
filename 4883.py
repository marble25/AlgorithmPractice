# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 29.
# time : 오후 10:39
# problem : https://www.acmicpc.net/problem/4883
# problem type : DP

# 정답률에 비해 굉장히 쉬운 문제
# 간선 경로에 맞게 dp를 잘 짜주면 된다
import sys

costs = [[0] * 3 for _ in range(100006)]
dp = [[0] * 3 for _ in range(100006)]

tc = 1
while True:
    n = int(sys.stdin.readline())
    if n == 0:
        break

    for i in range(n):
        costs[i] = list(map(int, sys.stdin.readline().split()))

    dp[0][0] = 999999999 # 0, 0은 애초에 갈 수 없으므로 비용도 최대로 설정
    dp[0][1] = costs[0][1] # 0, 1은 자기 자신이 곧 비용
    dp[0][2] = costs[0][1] + costs[0][2] # 0, 2는 0, 1에서만 올 수 있으므로 그 둘의 비용의 합


    for i in range(1, n):
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + costs[i][0] # i, 0은 좌측 상단, 중앙 상단 중 최소값을 받아옴
        dp[i][1] = min(dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i][0]) + costs[i][1] # i, 1은 좌측 상단, 중앙 상단, 우측 상단(모두 값이 계산됨), 바로 왼쪽에서 최소값을 받아옴
        dp[i][2] = min(dp[i-1][1], dp[i-1][2], dp[i][1])+ costs[i][2] # i, 2는 중앙 상단, 우측 상단, 바로 왼쪽인 중앙에서 최소값을 받아옴

    print('{}. {}'.format(tc, dp[n-1][1]))
    tc += 1