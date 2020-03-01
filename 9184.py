# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 1.
# time : 오후 2:53
# problem : https://www.acmicpc.net/problem/9184
# problem type : DP

# 간단한 DP 문제
# 함수 내용을 문제에서 제시해주었기 때문에 메모이제이션만 잘 해주면 accept
def w(a, b, c):
    global dp
    if a <= 0 or b <= 0 or c <= 0:
        return 1
    if a > 20 or b > 20 or c > 20:
        return w(20, 20, 20)
    if dp[a][b][c] != 0: return dp[a][b][c]

    if a < b and b < c:
        dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
    else:
        dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

    return dp[a][b][c]

dp = [[[0] * 25 for _ in range(25)] for __ in range(25)]

import sys

sys.setrecursionlimit(1000000)

while True:
    a, b, c = map(int, sys.stdin.readline().split())
    if a == b == c == -1:
        break
    result = w(a, b, c)
    print('w({}, {}, {}) = {}'.format(a, b, c, result))