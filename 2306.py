# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 12.
# time : 오전 12:56
# problem : https://www.acmicpc.net/problem/2306
# problem type : DP

# 처음에 생각해놓은 방법이 있었는데, 그 방법대로 안하고 새로운 방법 떠올려서 하다가 망한 문제
# 방법이 있으면 일단 구현해보자

import sys
sys.setrecursionlimit(1000000)
s = input().strip()

dp = [[-1] * len(s) for _ in range(len(s))]

# 구간을 잘라서 센 것과 통째로 센 것 중 최댓값을 구함
def solve(start, end):
    if dp[start][end] != -1: return dp[start][end]

    dp[start][end] = 0

    if (s[start] == 'a' and s[end] == 't') or (s[start] == 'g' and s[end] == 'c'): # 끝이랑 시작이랑 매칭되면 시작과 끝 뺀 나머지를 다시 재귀로 돌림
        dp[start][end] = solve(start+1, end-1) + 2

    for i in range(start, end): # start~i와 i+1~end로 구간을 끊어서 더한 것으로 update
        dp[start][end] = max(dp[start][end], solve(start, i) + solve(i+1, end))

    return dp[start][end]

print(solve(0, len(s)-1))
