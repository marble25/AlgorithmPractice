# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 11.
# time : 오후 7:05
# problem : https://www.acmicpc.net/problem/1947
# problem type : DP

# 점화식을 어찌어찌 유도는 했는데 그게 확실히 맞는지 증명하기 어려웠던 문제

n = int(input())
dp = [0] * (1000005)
dp[1] = 0
dp[2] = 1

# dp[i]를 생각해보자
# 1번 사람이 i에게 선물을 주었을 때
# i번 사람이 1번 사람을 선택한다면 dp[i-2]이고,
# 선택하지 않는다면 1번 사람이 i번 사람에게만 선물을 주었으니 dp[i-1]이다.
# i는 1을 제외한 모든 것이 될 수 있으므로 앞에 (i-1)을 곱해준다.
for i in range(3, n+1):
    dp[i] = ((i-1) * (dp[i-1] + dp[i-2])) % 1000000000

print(dp[n])