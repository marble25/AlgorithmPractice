# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 5.
# time : 오전 12:11
# problem : https://www.acmicpc.net/problem/2662
# problem type : DP

# for문 방향을 잘못 적어서 어이없게 틀린 문제 ㅜㅜ
# 작은 것도 다시 한번 보기
import sys

n, m = map(int, sys.stdin.readline().split())
benefits = [[0] * m]
for i in range(n):
    input_arr = list(map(int, sys.stdin.readline().split()))
    benefits.append(input_arr[1:])

# dp[i][j] : j개의 기업만 이용해서 i만원을 투자했을 때 얻을 수 있는 최대 이익
dp = [[0] * m for _ in range(n+1)]

# dp에 0번 기업 값을 넣어놓는다
for i in range(1, n+1):
    dp[i][0] = benefits[i][0]

for k in range(1, m):
    for i in range(1, n+1):
        for j in range(0, i+1):
            dp[i][k] = max(dp[i][k], dp[i-j][k-1] + benefits[j][k]) # dp[i][k]값을 k번째 기업에서 j만원을 투자하고, 나머지 기업들에서 i-j만원 투자한 것으로 업데이트

print(dp[n][m-1])

# 끝에서부터 역으로 돌면서 투자한 액수 기록하기
cost = n
result_arr = []
for i in range(m-1, 0, -1):
    for j in range(0, cost+1):
        if dp[cost-j][i-1] + benefits[j][i] == dp[cost][i]:
            result_arr.append(j)
            cost -= j
            break

result_arr.append(cost)
result_arr.reverse() # 역순으로 집어넣었으므로 배열을 다시 reverse

for element in result_arr:
    print(element, end=' ')