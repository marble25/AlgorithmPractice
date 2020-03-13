# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 13.
# time : 오후 10:21
# problem : https://www.acmicpc.net/problem/5721
# problem type : DP

# 간단한 DP 문제
# n*m의 범위로 주어져 있어서 시간 초과날 까봐 걱정했는데 다행히 나지는 않았음.

import sys
while True:
    m, n = map(int, sys.stdin.readline().split())
    arr = []
    if m == n == 0: break

    for i in range(m):
        arr.append(list(map(int, sys.stdin.readline().split())))

    # 한 줄에 대해서 두 칸 이상 뛰어넘는 것이 가능한 dp 배열을 만듦
    max_list = [0] * m # 한 줄마다 가져갈 수 있는 사탕 최대를 저장하는 배열
    dp = [[[0] * 2 for _ in range(n)] for __ in range(m)]
    for i in range(m):

        # 초기값 설정
        dp[i][0][1] = arr[i][0]
        max_list[i] = arr[i][0]
        if n >= 2:
            dp[i][1][0] = arr[i][0]
            dp[i][1][1] = arr[i][1]
            max_list[i] = max(arr[i][1], max_list[i])

        for j in range(2, n):
            dp[i][j][0] = max(dp[i][j-1][1], dp[i][j-1][0]) # i, j에서 박스를 안고른다는 것은 i, j-1에서 박스를 고르거나 안고른 경우 중 최댓값을 가져옴
            dp[i][j][1] = dp[i][j-1][0] + arr[i][j] # i, j에서 박스를 고른다면 i, j-1에서 안고른 경우이다. 이 경우 값에다 박스 고른 값을 더해줌

            max_list[i] = max(dp[i][j][0], dp[i][j][1], max_list[i])

    # max_list를 바탕으로 다시 한번 dp를 돌려준다.
    max_dp = [[0] * 2 for _ in range(m)]
    max_dp[0][1] = max_list[0]
    max_val = max_list[0]
    if m >= 2:
        max_dp[1][0] = max_list[0]
        max_dp[1][1] = max_list[1]
        max_val = max(max_val, max_list[1])

    for i in range(2, m):
        max_dp[i][0] = max(max_dp[i-1][1], max_dp[i-1][0]) # i에서 박스를 안 고른다는 것은 i-1에서 고르거나 안고른 경우 중 최댓값을 가져온다는 이야기다.
        max_dp[i][1] = max_dp[i-1][0] + max_list[i] # i에서 박스를 고르면 i-1은 안골라야 한다.
        max_val = max(max_val, max_dp[i][0], max_dp[i][1]) # max값을 업데이트한다.

    print(max_val)
