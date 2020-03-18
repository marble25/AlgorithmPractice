# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 18.
# time : 오전 11:31
# problem : https://www.acmicpc.net/problem/1727
# problem type : DP

def dfs(x, y):
    global dp
    if x == n: return 0
    if y == m: return 987654321
    if n-x > m-y: return 987654321
    if dp[x][y] != 987654321: return dp[x][y]
    dp[x][y] = min(dfs(x, y+1), dfs(x+1, y+1) + abs(s1[x]-s2[y]))
    return dp[x][y]

import sys
sys.setrecursionlimit(10 ** 7)
n, m = map(int, sys.stdin.readline().split())
s1 = list(map(int, sys.stdin.readline().split()))
s2 = list(map(int, sys.stdin.readline().split()))

s1.sort()
s2.sort()

if n > m:
    n, m = m, n
    s1, s2 = s2, s1

dp = [[987654321] * 1005 for _ in range(1005)]
print(dfs(0, 0))