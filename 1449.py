# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 7.
# time : 오전 10:54
# problem : https://www.acmicpc.net/problem/1449
# problem type : Greedy

n, l = map(int, input().split())
arr = list(map(int, input().split()))

arr.sort()

# 왼쪽에서 l만큼 테이프를 붙이고, 그 것을 초과한다면 새로 테이프 붙임
start = 0
count = 0
for i in range(n):
    if start > arr[i]:
        continue

    count += 1
    start = arr[i] + l

print(count)