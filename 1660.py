# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 5.
# time : 오전 10:39
# problem : https://www.acmicpc.net/problem/1660
# problem type : DP

# python3으로 제출했더니 시간초과...

# 사면체 갯수 테이블을 미리 만들어 놓음
table = [0, 1]
for i in range(2, 300):
    table.append(table[i-1] + i * (i+1) // 2)

n = int(input())

# dp[i] : i개의 대포알로 만들 수 있는 최소 사면체 갯수
dp = [987654321] * 300005
dp[0] = 0
dp[1] = 1
for i in range(n+1):
    for j in range(300):
        if table[j] > i: break
        dp[i] = min(dp[i], dp[i-table[j]] + 1) # 이전에 계산한 값(dp[i-table[j]])에 사면체 하나 추가한 값이 최소이면 업데이트

print(dp[n])