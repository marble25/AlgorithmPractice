# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 9.
# time : 오전 2:07
# problem : https://www.acmicpc.net/problem/1126
# problem type : DP

# 두 탑의 차이라는 아이디어가 중요했던 문제

import sys

sys.setrecursionlimit(1000000)

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

dp = [[-1] * 250005 for _ in range(50)]


def f(index, height_diff):
    if height_diff > 250000: return -987654321  # 높이 차이가 250000가 넘으면 결코 따라잡을 수 없음
    if index == n:  # n번째까지 도달했을 때
        if height_diff == 0:
            return 0
        else:
            return -987654321

    if dp[index][height_diff] != -1:  # 값이 있으면 return
        return dp[index][height_diff]

    dp[index][height_diff] = -987654321
    dp[index][height_diff] = max(dp[index][height_diff], f(index + 1, height_diff))  # 블럭 사용 X
    dp[index][height_diff] = max(dp[index][height_diff], f(index + 1, height_diff + arr[index]))  # 블럭을 큰쪽에다 쌓음
    dp[index][height_diff] = max(dp[index][height_diff],
                                 f(index + 1, abs(height_diff - arr[index])) +
                                 min(arr[index], height_diff))  # 블럭을 작은 쪽에다 쌓음
                                                                # 만약 height_diff가 arr[index]보다 크면 차이를 줄이고 arr[index]만큼 값 증가
                                                                # 아니라면 height_diff가 역전되고, 시작되는 높이는 height_diff만큼 값 증가

    return dp[index][height_diff]


result = f(0, 0)
print(result if result != 0 else -1) # 아무것도 안쓴다면 result가 0이 나옴