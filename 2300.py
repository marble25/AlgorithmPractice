# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 18.
# time : 오후 12:03
# problem : https://www.acmicpc.net/problem/2300
# problem type : DP

# 자꾸 사소한 것에서 틀릴 때
# 자괴감이 든다.
# 이런 쉬운 문제를 풀지 못한 나에게 화가 난다.
# 실수를 무조건 줄여야 한다.

import sys

n = int(sys.stdin.readline())
arr = []
for i in range(n):
    x, y = map(int, sys.stdin.readline().split())
    arr.append((x, abs(y)))

arr.sort()
arr.insert(0, (0, 0))

dp = [987654321] * (n+1)
dp[0] = 0
for i in range(1, n+1):
    lx = arr[i][0]
    rx = arr[i][0]
    max_y_value = arr[i][1]
    for j in range(i-1, -1, -1): # j에서 시작되는 사각형을 생각해보자
        length = max(rx-lx, max_y_value * 2) # x값 차이와 y값 절대값의 2배 중 큰 값이 사각형의 변 길이
        dp[i] = min(dp[i], length + dp[j]) # 이전 dp에 변 길이를 더한 것을 dp에 업데이트
        lx = arr[j][0] # 좌측 좌표
        max_y_value = max(arr[j][1], max_y_value) # 가장 긴 y값 길이

print(dp[n])