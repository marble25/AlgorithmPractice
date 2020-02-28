# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 29.
# time : 오전 12:51
# problem : https://www.acmicpc.net/problem/2482
# problem type : DP

# 생각하기 까다로웠던 문제
# for문 시작 변수가 무엇이냐에 따라 결과값이 달라짐

n = int(input())
k = int(input())

# dp[i][j] : i개의 색상환 중 j개로 선택하는 경우의 수
dp = [[0] * (k+1) for _ in range(n+1)]

# i색상을 첫 번째로 선택하는 경우의 수는 i이므로 initialize
for i in range(1, n+1):
    dp[i][1] = i

for i in range(4, n+1): # 1, 2, 3까지는 2개 이상 선택하는 경우가 없으므로 4부터 시작
    for j in range(2, k+1): # 1은 이미 initialize 했으므로 k까지
        dp[i][j] = (dp[i-1][j] + dp[i-2][j-1]) % 1000000003 # i번째 색을 안고른 경우와 i번째 색을 고른 경우의 합을 dp에 저장

print(dp[n][k])