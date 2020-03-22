# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 10.
# time : 오후 11:22
# problem : https://www.acmicpc.net/problem/3079
# problem type : Binary Search

# 간단한 이분 탐색 문제

import sys

# n : 심사대 수
# m : 사람 수
n, m = map(int, sys.stdin.readline().split())
arr = []
for i in range(n):
    arr.append(int(sys.stdin.readline()))

low, high = 1, 1000000000000000000
ans = 1000000000000000000

while low <= high:
    mid = (low + high) // 2 # mid : 걸리는 시간의 최솟값
    sum = 0
    for i in range(n):
        sum += mid // arr[i] # sum : 심사받을 수 있는 사람의 최댓값

    if sum >= m: # m명 이상 심사 가능하면 답이 가능하다.
        ans = min(ans, mid)
        high = mid - 1
    else:
        low = mid + 1

print(ans)