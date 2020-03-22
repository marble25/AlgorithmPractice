# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 12.
# time : 오후 8:44
# problem : https://www.acmicpc.net/problem/1670
# problem type : DP, Math

# 발상만 할 수 있으면 간단한 문제
# 어떤 점에서 다른 점을 선택할 때, 그 사이에 있는 점의 갯수가 짝수가 되게 나누면 된다.
# 이때, 시작점을 굳이 옮기지 않아도 되므로 나눈 것들의 합이 답이다.

n = int(input())
dp = [0] * (n+1)
dp[0] = 1
dp[2] = 1
for i in range(4, n+1, 2):
    for j in range(0, i-1, 2): # 선택한 2개 점을 빼면 i-2개가 남고, 이 것을 짝수와 짝수로 나누어 경우의 수를 각각 곱해준 후 더하면 답
        dp[i] = (dp[i] + dp[j] * dp[i-j-2]) % 987654321

print(dp[n])