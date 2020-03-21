# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 21.
# time : 오후 8:12
# problem : https://www.acmicpc.net/problem/2961
# problem type : DP

# 문제가 약간 이상한 문제
# 문제에 설명을 제대로 안써놓아서 힌트 없이는 못푸는 문제

import sys
n, k = map(int, sys.stdin.readline().split())
dp = [0] * 360
arr = list(map(int, sys.stdin.readline().split()))

dp[0] = dp[90] = dp[180] = dp[270] = 1

for i in range(n):
    for j in range(0, 360):
        dp[(arr[i]*j)%360] = 1 # arr[i]를 j번 사용
        dp[abs(-arr[i]*j)%360] = 1 # arr[i]를 음의 방향으로 j번 사용
        if dp[j] == 0: continue # j가 없는 각도이면 continue
        for k in range(0, 360):
            if (arr[i] * k) % 360 == arr[i]: break # 다시 같은 각도로 돌아온다면 break (최소화)
            dp[abs(j-arr[i]*k) % 360] = 1 # j각도에서 arr[i]를 k번 뺀 각도 추가
            dp[(j+arr[i]*k) % 360] = 1 # j각도에서 arr[i]를 k번 더한 각도 추가

query = list(map(int, sys.stdin.readline().split()))
for q in query:
    print('YES' if dp[q] == 1 else 'NO')