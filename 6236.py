# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 11.
# time : 오후 5:14
# problem : https://www.acmicpc.net/problem/6236
# problem type : Binary Search

# Binary Search에는 어느 정도 자신감이 붙게 해준 문제

import sys
n, m = map(int, sys.stdin.readline().split())

arr = []
max_value = 0
for i in range(n):
    arr.append(int(sys.stdin.readline()))
    max_value = max(max_value, arr[i])

low, high = max_value, 1000000000 # high을 금액 최대 * m 최대로 잡음)
ans = 1000000000
while low <= high:
    mid = (low + high) // 2 # 인출 금액
    current_money = mid # 현재 가지고 있는 돈
    cnt = 1 # 인출 횟수
    for i in range(n):
        if current_money >= arr[i]: # 가진 돈이 많으면 가진 돈에서 사용
            current_money -= arr[i]
        else: # 가진 돈이 없으면 인출해서 사용
            current_money = mid - arr[i]
            cnt += 1

    if cnt <= m:
        ans = min(ans, mid)
        high = mid - 1
    else:
        low = mid + 1

print(ans)