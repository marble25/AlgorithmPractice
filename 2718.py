# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 13.
# time : 오전 11:39
# problem : https://www.acmicpc.net/problem/2718
# problem type : DP

# 경우의 수 세는 것이 까다로웠던 문제

# dp[i] : i 상태에서
# dp[i][0] : ....
# dp[i][1] : ..xx
# dp[i][2] : .xx.
# dp[i][3] : x..x
# dp[i][4] : xx..
# 이런 식으로 만들어진 총 경우의 수

dp = [[0] * 5 for _ in range(105)]
dp[0][0] = 1
for i in range(100):
    dp[i+1][3] += dp[i][0]
    dp[i+1][4] += dp[i][0]
    dp[i+1][0] += dp[i][0]
    dp[i+1][1] += dp[i][0]
    dp[i+2][0] += dp[i][0]

    dp[i+1][4] += dp[i][1]
    dp[i+1][0] += dp[i][1]

    dp[i+1][3] += dp[i][2]

    dp[i+1][2] += dp[i][3]
    dp[i+1][0] += dp[i][3]

    dp[i+1][1] += dp[i][4]
    dp[i+1][0] += dp[i][4]


T = int(input())

for _ in range(T):
    x = int(input())
    print(dp[x][0])