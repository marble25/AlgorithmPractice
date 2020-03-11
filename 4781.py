# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 11.
# time : 오후 8:04
# problem : https://www.acmicpc.net/problem/4781
# problem type : DP

# float에서 int로 바꾸는 과정에서 오차가 생기는 것!!
# 이 것을 인지하고 있어야 한다.

import sys

while True:
    n, m = map(float, sys.stdin.readline().split())

    if n == 0 and m == 0: break
    n = int(n)
    m = int(m * 100+0.5)

    arr = []
    for i in range(n):
        x, y = map(float, sys.stdin.readline().split())
        arr.append((int(x), int(y * 100+0.5)))

    dp = [0] * 10005
    for i in range(1, m+1):
        for j in range(n):
            if i < arr[j][1]: continue
            dp[i] = max(dp[i-arr[j][1]] + arr[j][0], dp[i])

    print(dp[m])