# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 29.
# time : 오후 4:00
# problem : https://www.acmicpc.net/problem/1351
# problem type : DP

import sys

sys.setrecursionlimit(1000000)
n, p, q = map(int, sys.stdin.readline().split())
dp = dict()
dp[0] = 1
def f(x, p, q):
    global dp
    if x in dp: return dp[x]
    dp[x] = f(x//p, p, q) + f(x//q, p, q)
    return dp[x]

print(f(n, p, q))