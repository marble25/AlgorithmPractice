# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 5.
# time : 오전 2:44
# problem : https://www.acmicpc.net/problem/11058
# problem type : DP

# 구현을 2차원으로 생각하다가 1차원으로 바꾼 문제
# 어차피 Ctrl-A, Ctrl-C, Ctrl-V 사이에는 A출력이 없으므로(출력하면 손해) 이 셋을 묶음으로 생각하면 편하다
n = int(input())

dp = [0] * 105

for i in range(1, n+1):
    dp[i] = i # 모두 1번 버튼만 누른 경우로 dp를 초기화
    for j in range(1, i-2):
        dp[i] = max(dp[i], dp[j] * (i-j-1)) # 1부터 i-3까지의 값 중 하나를 버퍼에 저장하고(Ctrl-C), 그 이후를 Ctrl-V만 했을 때 갯수

print(dp[n])