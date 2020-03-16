# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 16.
# time : 오후 6:19
# problem : https://www.acmicpc.net/problem/2792
# problem type : Binary Search

# 간단한 이분탐색 문제
# 가장 많은 보석을 가져간 학생의 보석 갯수를 찾도록 이분 탐색을 세팅

import sys
import math
n, m = map(int, sys.stdin.readline().split())
arr = []
for i in range(m):
    arr.append(int(sys.stdin.readline()))

low = 1
high = 10 ** 9
result = 10 ** 9
while low <= high:
    mid = (low + high) // 2
    person_count = 0
    for i in range(m):
        person_count += math.ceil(arr[i] / mid) # mid개씩 나누어 주었을 때 받을 수 있는 학생의 수

    if person_count <= n: # 학생의 수가 n보다 작으므로 답이 될 수 있는 경우
        high = mid - 1
        result = min(mid, result)
    elif person_count > n: # 학생 수가 n보다 크므로(보석이 남으므로) 답이 될 수 없는 경우
        low = mid + 1

print(result)
