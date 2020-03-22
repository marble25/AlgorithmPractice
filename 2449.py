# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 5.
# time : 오전 11:02
# problem : https://www.acmicpc.net/problem/2449
# problem type : DP

# 풀이법이 생각나지 않아서 게시글 좀 참고해서 문제 해결

import sys
sys.setrecursionlimit(100000)

n, k = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
dp = [[-1] * 205 for _ in range(205)] # dp[i][j] : i~j 구간의 전구를 arr[i] 색으로 바꾸는데 필요한 최소 횟수

def f(start, end):
    global n, k, arr
    global dp

    if start == end:
        return 0

    if dp[start][end] != -1: return dp[start][end]
    dp[start][end] = 987654321
    for i in range(start, end): # start부터 i까지와 i+1부터 end까지 구간으로 나눔
        left = f(start, i)
        right = f(i+1, end)
        temp = 0 if arr[start] == arr[i+1] else 1 # 구간 시작점의 색이 같으면 0, 다르면 1

        dp[start][end] = min(dp[start][end], left+right+temp)

    return dp[start][end]

print(f(0, n-1))