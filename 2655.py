# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 20.
# time : 오후 9:52
# problem : https://www.acmicpc.net/problem/2655
# problem type :

# heapq로 풀려고 하다가 틀려서 왜그런지 분석해보고 dp로 풀이법을 바꾼 문제
# LIS 방식으로 풀면 쉽게 풀리는 문제

import sys

n = int(sys.stdin.readline())
arr = []
for i in range(n):
    bottom, height, weight = map(int, sys.stdin.readline().split())
    arr.append((bottom, weight, height, i+1)) # bottom, weight 순서로 정렬시킬려고 순서를 바꿈

arr.sort(reverse=True)

# dp[i] : i번째까지 벽돌까지를 조합해서 나올 수 있는 최대 높이
dp = [0] * n
dp[0] = arr[0][2]

# trace : 부모를 추적하는 리스트
trace = [0] * n
trace[0] = -1

for i in range(1, n):
    for j in range(i+1):
        if arr[i][0] < arr[j][0] and arr[i][1] < arr[j][1]: # arr[i]가 arr[j] 위에 올라갈 수 있으면
            if dp[i] < dp[j] + arr[i][2]: # 높이가 최대라면
                dp[i] = dp[j] + arr[i][2]
                trace[i] = j # i의 부모를 j로 설정
    if dp[i] == 0: # LIS가 구성이 안되면
        dp[i] = arr[i][2]
        trace[i] = -1 # 부모를 -1로

# 가장 큰 높이를 찾음
max_val = -1
max_index = 0
for i in range(n):
    if dp[i] > max_val:
        max_val = dp[i]
        max_index = i

# 가장 큰 높이에서 역으로 가며 시작 노드까지 result_list에 저장
result_list = []
while max_index != -1:
    result_list.append(arr[max_index][3])
    max_index = trace[max_index]

print(len(result_list))
print(' '.join(map(str, result_list)))