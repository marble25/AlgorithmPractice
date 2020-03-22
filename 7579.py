# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 24.
# time : 오전 12:18
# problem : https://www.acmicpc.net/problem/7579
# problem type : DP

# Knapsack Problem(배낭 문제)로 풀기

# n, m, a, c 입력 받기
n, m = map(int, input().split())
a = list(map(int, input().split()))
c = list(map(int, input().split()))

# answer_list[i][j]는 0~i까지의 앱을 사용하여 j라는 비용을 들였을 때 나올 수 있는 최대 메모리
answer_list = [[0] * 10005 for _ in range(105)]

for i in range(n):
    for j in range(10005):
        if i == 0 and j >= c[i]: # 첫 번째 row setting하기
            answer_list[i][j] = a[i]
            continue

        if j < c[i]:
            answer_list[i][j] = answer_list[i-1][j]
            continue

        answer_list[i][j] = max(answer_list[i-1][j], answer_list[i-1][j-c[i]] + a[i]) # i앱은 사용하지 않는 경우와 i앱 사용하는 경우 중 최대값을 구함

# 최소 비용을 출력
for i in range(10005):
    if answer_list[n-1][i] >= m:
        print(i)
        break
