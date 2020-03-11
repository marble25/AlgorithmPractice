# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 12.
# time : 오전 12:14
# problem : https://www.acmicpc.net/problem/2515
# problem type : DP

# 어렵지 않았던 문제 같은데 문제 이해를 제대로 못했던 문제
# 문제를 꼭 잘 이해해야겠다.

import sys
sys.setrecursionlimit(10000)
n, s = map(int, sys.stdin.readline().split())
arr = []
for i in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))

# 높이 오름차순, 가격 내림차순 정렬
arr.sort(key=lambda x: (x[0], -x[1]))

# 차이가 S 이상 나는 값 중 가장 끝에 있는 index를 리턴
def search(index):
    low, high = 0, index-1
    while low <= high:
        mid = (low + high) // 2
        if arr[index][0] - arr[mid][0] >= s: low = mid + 1
        else: high = mid - 1

    return high

dp = [[0] * 2 for _ in range(n)]
dp[0][0] = arr[0][0]
dp[0][1] = arr[0][1]
for i in range(1, n):
    if arr[i][0] >= dp[i-1][0] + s: # 바로 전 그림과 차이가 s 이상 나면 그대로 더해주면 됨
        dp[i][0] = arr[i][0]
        dp[i][1] = dp[i-1][1] + arr[i][1]
    else:
        prev_index = search(i) # 차이가 s 이상 나는 그림 중 가장 index가 큰 것
        if dp[prev_index][1] + arr[i][1] > dp[i-1][1]: # 이전 그림에 현재 그림 가격 더한게 바로 직전의 dp값보다 크면 update
            dp[i][0] = arr[i][0]
            dp[i][1] = dp[prev_index][1] + arr[i][1]
        else: # 아니면 그대로 유지
            dp[i][0] = dp[i-1][0]
            dp[i][1] = dp[i-1][1]

print(dp[n-1][1])