# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 19.
# time : 오전 11:54
# problem : https://www.acmicpc.net/problem/3067
# problem type : DP

# 쉬운 DP 문제

import sys
T = int(sys.stdin.readline())

for _ in range(T):
    n = int(sys.stdin.readline())
    coins = [0] + list(map(int, sys.stdin.readline().split()))
    m = int(sys.stdin.readline())

    dp = [0] * 10005
    dp[0] = 1 # 동전이 하나도 없으면 0원을 표현할 수 있다.
    for i in range(1, len(coins)): # i개의 동전으료 표현하기
        for j in range(coins[0], m+1):
            if j-coins[i] >= 0:
                dp[j] += dp[j-coins[i]] # j금액은 j-coins[i]로 표현한 가짓수에 coins[i]를 더해준 것들의 합과 같다.
    print(dp[m])