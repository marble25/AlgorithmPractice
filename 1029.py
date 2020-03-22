# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 22.
# time : 오전 12:26
# problem : https://www.acmicpc.net/problem/1029
# problem type : DP, Bitmask

# 비트마스크를 써야 해서 꽤 어려웠던 문제

def f(state, artist, c, depth):
    global dp
    if dp[state][artist][c] != -1: return dp[state][artist][c]
    dp[state][artist][c] = depth

    for i in range(n):
        if state & (1 << i) or arr[artist][i] < c: continue # i번째 아티스트를 방문했거나 i번째 아티스트로 가는 비용이 현재 비용보다 작으면 continue
        dp[state][artist][c] = max(dp[state][artist][c], f(state | (1 << i), i, arr[artist][i], depth+1)) # 갈 수 있는 경로 중 최댓값을 저장

    return dp[state][artist][c]

import sys
n = int(sys.stdin.readline())
arr = [[] for _ in range(n)]
for i in range(n):
    input_line = sys.stdin.readline().strip()
    for j in range(n):
        arr[i].append(ord(input_line[j]) - ord('0'))

dp = [[[-1] * 10 for __ in range(n+1)] for _ in range(1 << 15)]

print(f(1, 0, 0, 1))