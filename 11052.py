# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 23.
# time : 오후 10:38
# problem : https://www.acmicpc.net/problem/11052

n = int(input())
p = list(map(int, input().split()))

# max_cost를 n+1개의 length 배열로 초기화
max_cost = [0 for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(n):
        if i - j < 1: break
        max_cost[i] = max(p[j] + max_cost[i-j-1], max_cost[i]) # i-j-1개의 카드를 사는 가장 비싼 값에 j번째 카드 값을 더한 값과 기존 값 비교

# n개의 카드를 사는 가장 비싼 값 출력
print(max_cost[n])