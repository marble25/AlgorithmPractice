# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 20.
# time : 오후 1:52
# problem : https://www.acmicpc.net/problem/9764
# problem type : DP

# Top-down 방식으로 제출해서 시간제한 걸릴 줄 알았는데 안걸렸던 문제

import sys
sys.setrecursionlimit(10 ** 6)

T = int(sys.stdin.readline())

def f(x, min_num):
    global dp
    if x < min_num: return -1
    if dp[x][min_num] != -1: return dp[x][min_num]
    dp[x][min_num] = 1
    for i in range(min_num, x // 2 + 1):
        ret = f(x-i, i+1)
        if ret != -1: dp[x][min_num] += ret
    return dp[x][min_num] % 100999

MAX_VAL = 2005

# dp = [[-1] * MAX_VAL for _ in range(MAX_VAL)]
dp = [[0] * MAX_VAL for _ in range(MAX_VAL)] # dp[i][j] : 1~j까지 자연수를 이용해서 i를 만드는 경우의 수
for i in range(2001):
    dp[0][i] = 1 # 0을 만드는 경우의 수는 항상 1
for i in range(1, 2001):
    for j in range(2001):
        dp[i][j] = dp[i][j-1] # 1~j-1까지 자연수를 이용해 i를 만드는 방법의 수
        if i >= j: dp[i][j] = (dp[i][j] + dp[i-j][j-1]) % 100999 # 1~j-1을 이용해 i-j를 만드는 방법의 수를 더해줌


for i in range(T):
    n = int(sys.stdin.readline())
    print(dp[n][n])
    # print(f(n, 1))

