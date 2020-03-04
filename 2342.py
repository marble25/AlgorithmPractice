# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 4.
# time : 오후 11:02
# problem : https://www.acmicpc.net/problem/2342
# problem type : DP

import sys

arr = [0]
input_arr = list(map(int, sys.stdin.readline().split()))
arr.extend(input_arr[:-1])

arr_len = len(arr)-1

# 초기값으로 매우 큰 값을 설정
dp = [[[987654321] * 5 for _ in range(5)] for __ in range(len(arr))]

# 발 처음 위치에서 움직이는 위치까지 움직이는데 드는 힘을 계산
def get_score(from_pos, to_pos):
    if from_pos == 0 or to_pos == 0: return 2
    if from_pos == to_pos: return 1
    if abs(to_pos - from_pos) == 2: return 4
    return 3

# 초기 힘 설정
dp[0][0][0] = 0

# dp[i][j][k] : i번째 스텝에서 (j, k) 위치로 오는데 드는 최소 힘
for i in range(arr_len):
    for j in range(0, 5):
        for k in range(0, 5):
            if j != arr[i+1]: # 다음 스텝의 두 발이 같은 지점일 때
                dp[i+1][j][arr[i+1]] = min(dp[i+1][j][arr[i+1]], dp[i][j][k] + get_score(k, arr[i+1])) # 다음 단계는 j값이 arr[i+1]로 바뀌거나 k값이 arr[i+1]로 바뀌거나 둘 중 하나이다
            if k != arr[i+1]: # 다음 스텝의 두 발이 같은 지점일 때
                dp[i+1][arr[i+1]][k] = min(dp[i+1][arr[i+1]][k], dp[i][j][k] + get_score(j, arr[i+1]))

min_result = 987654321
for i in range(0, 5):
    min_result = min(min_result, dp[arr_len][i][arr[arr_len]], dp[arr_len][arr[arr_len]][i]) # 마지막 스텝의 경우 중 가장 작은 값을 출력

print(min_result)