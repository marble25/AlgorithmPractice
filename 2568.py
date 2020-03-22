# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 19.
# time : 오후 1:51
# problem : https://www.acmicpc.net/problem/2568
# problem type : DP, LIS

# nlogn으로 풀어본 LIS 문제

import sys
import bisect

n = int(sys.stdin.readline())
arr = []
for i in range(n):
    x, y = map(int, sys.stdin.readline().split())
    arr.append((x, y, i))

arr.sort()

lis = [-987654321]
trace = [0] * n
for i in range(n):
    if lis[-1] < arr[i][1]: # lis의 마지막이 arr[i][1]보다 작으면 lis 마지막에다 붙임
        lis.append(arr[i][1])
        trace[i] = len(lis)-1 # lis index를 trace에 저장
    else:
        index = bisect.bisect_left(lis, arr[i][1]) # lis에서 arr[i][1]보다 큰 값중 가장 작은 값의 index를 구함(이 index부터 arr[i][1]보다 큼)
        lis[index] = arr[i][1] # lis[index]를 arr[i][1]로 바꿔치기
        trace[i] = index # lis index를 trace에 저장

# 끝에서부터 돌면서 lis[cur]을 채운 i들을 체크(진짜 lis)
# trace에 같은 i가 있다면 뒤가 우선순위(뒤쪽에서 바꿔치기했을 수 있기 때문)
visited = [False] * n
cur = len(lis)-1
for i in range(n-1, -1, -1):
    if cur == trace[i]:
        visited[i] = True
        cur -= 1

print(n - (len(lis)-1))
for i in range(n):
    if not visited[i]: print(arr[i][0]) # lis가 아닌, 제거할 값들을 출력