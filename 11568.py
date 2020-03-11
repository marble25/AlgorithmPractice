# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 11.
# time : 오후 6:39
# problem : https://www.acmicpc.net/problem/11568
# problem type : DP

# 어이없는 실수로 틀린 문제
# 기저 조건을 꼼꼼히 확인해야 한다.

import sys
n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

# dp[i] : i를 포함하는 증가 수열의 길이 중 최댓값
dp = [1] * (n+1) # 자기 자신부터 시작하는 경우 dp값은 1이다
ans = 0
for i in range(0, n):
    dp[i] = 1
    for j in range(0, i):
        if arr[j] < arr[i]: # 증가수열을 만들 수 있다면 최댓값 갱신
            dp[i] = max(dp[j]+1, dp[i])

    ans = max(dp[i], ans) # 지금까지 나온 증가수열 중 최댓값 저장

print(ans)