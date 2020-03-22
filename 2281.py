# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 21.
# time : 오후 10:11
# problem : https://www.acmicpc.net/problem/2281
# problem type : DP

# 깔끔하게 clear 한 문제

import sys
n, m = map(int, sys.stdin.readline().split())
arr = []
for i in range(n):
    arr.append(int(sys.stdin.readline()))

# dp[i][j] : i번째 이름까지 적었을 때 현재 j칸에 있을 때 남게 되는 칸 수 제곱 최솟값
dp = [[987654321] * (m+1) for _ in range(n+1)]
dp[0][arr[0]-1] = 0 # 첫 번째 값을 대입해 놓는다.
for i in range(1, n):
    for j in range(m):
        if dp[i-1][j] == 987654321: continue # 가능하지 않은 경우 배제
        if j+arr[i]+1 < m: # 칸 안에 들어올 수 있으면 들어오는 경우도 추가
            dp[i][j+arr[i]+1] = min(dp[i][j+arr[i]+1], dp[i-1][j])
        dp[i][arr[i]-1] = min(dp[i][arr[i]-1], (m-1-j) ** 2 + dp[i-1][j]) # 다음 줄로 넘어가는 경우(현재 줄에서 남은 칸의 제곱을 더해줌)

min_val = 987654321
for i in range(m):
    min_val = min(dp[n-1][i], min_val)

print(min_val)