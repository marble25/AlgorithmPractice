# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 28.
# time : 오후 6:33
# problem : https://www.acmicpc.net/problem/2624
# problem type : DP

# 완전탐색으로 풀려다가 시간초과로 DP Bottom-Up 방식으로 풀게 됨

import sys

T = int(sys.stdin.readline())
k = int(sys.stdin.readline())
coins = []

dp = [[0] * (k+1) for _  in range(T + 1)]
available_prices = [0]

for _ in range(k):
    coins.append(list(map(int, sys.stdin.readline().split())))

# coin을 내림차순으로 정렬
coins.sort(key=lambda coin:coin[0], reverse=True)

# dp[price][stage] : stage 이전까지의 동전을 사용해서 만들 수 있는 price의 가짓수
dp[0][0] = 1
for i in range(k):
    for available_price in range(0, 10001):
        for j in range(0, coins[i][1]+1):
            price = available_price + j * coins[i][0]
            if price > T:
                break

            dp[price][i+1] += dp[available_price][i] # 현재 가능한 price에 새로 들어온 동전을 사용해서 만든 가짓수를 업데이트 시킴

print(dp[T][k])