# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 17.
# time : 오후 9:50
# problem : https://www.acmicpc.net/problem/1028
# problem type : DP

# 왜 이렇게 많이 틀렸는지 이유를 모르겠는 문제
# 잘 생각하면 쉽게 풀 수 있었는데, 조건 하나하나 꼼꼼히 따져가면서 풀어야 했다.
# 대각선의 길이를 저장해서 모든 점에서 구한 대각선 길이를 가지고 다이아몬드를 만들 수 있는지 체크


import sys
n, m = map(int, sys.stdin.readline().split())

arr = ['0' * (m+2)] # i, j가 범위에서 벗어나는지 체크하는 것을 안하려고 패딩을 줌
for i in range(n):
    arr.append('0' + sys.stdin.readline().strip() + '0')
arr.append('0' * (m+2))

dp = [[[0] * 2 for _ in range(m+2)] for _ in range(n+2)]
for i in range(1, n+1):
    for j in range(1, m+1):
        if arr[i][j] == '1': # 현재값이 1이면 오른쪽 아래로 향하는 선(1)과 왼쪽 아래로 향하는 선(0)의 길이에 +1을 해줌
            dp[i][j][1] = dp[i-1][j-1][1] + 1
            dp[i][j][0] = dp[i-1][j+1][0] + 1

result = 0
for i in range(1, n+1):
    for j in range(1, m+1):
        length = min(dp[i][j][0], dp[i][j][1]) # i, j로 올 수 있는 대각선 중 짧은 것을 length로 정함
        for l in range(length-1, result-1, -1): # 이 점이 아랫 꼭짓점이 되는 모든 다이아몬드의 길이를 l로 함
            if dp[i-l][j-l][0] >= l+1 and dp[i-l][j+l][1] >= l+1: # 왼쪽 꼭짓점의 오른 대각선 최대 길이가 l+1보다 크거나 같고 오른쪽 꼭짓점의 왼 대각선 최대 길이가 l+1보다 크거나 같으면 result 업데이트
                result = l+1
                break
print(result)