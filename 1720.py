# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 5.
# time : 오후 9:15
# problem : https://www.acmicpc.net/problem/1720
# problem type : DP

# 간단한 dp문제
n = int(input())
dp = [0] * 35
dp[0] = 1
dp[1] = 1
for i in range(2, n+1): # dp[i]는 i-1까지 배열한 모양에 세로로 2*1 하나 놓는것과 i-2까지 배열한 모양에 가로로 2*1 2개 혹은 2*2 1개 놓는 것과 같다
    dp[i] = dp[i-1] + dp[i-2] * 2

# 중복된 경우 제거
# 중앙선을 기준으로 양쪽 모양이 대칭인 경우를 한번 더해준 후 2로 나누어 주면 결과가 나옴

# n이 홀수 : 중앙에 2*1 세로로 하나 있고 양쪽으로 똑같은 모양으로 대칭되어 있음
# n이 짝수 : 중앙선을 기준으로 같은 모양이거나 중앙선에 걸쳐 있는((n-2)/2까지 모양이 있고 가로로 2*1 2개 또는 2*2 하나 놓는) 모양으로 대칭되어 있음
result = dp[n] + dp[n//2]
if n % 2 == 0:
    result += 2*dp[(n-2)//2]

print(result // 2)