# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 12.
# time : 오후 8:24
# problem : https://www.acmicpc.net/problem/1-43
# problem type : Graph

# 간단한 문제

import sys
n, m = map(int, sys.stdin.readline().split())
input_line = sys.stdin.readline().split()
danger = dict.fromkeys(list(map(int, input_line[1:])), 1) # 진실을 알고있는 사람들을 dict로 만들어 놓는다.
arr = [[] for _ in range(m)]
for i in range(m):
    input_line = sys.stdin.readline().split()
    arr[i] = list(map(int, input_line[1:]))

danger_len = len(danger)
visited = [0] * (m)
while True:
    for i in range(m):
        if visited[i] == 1: continue # 이미 위험한 파티는 생각하지 않아도 된다.

        flag = False
        for attender in arr[i]:
            if attender in danger: # 파티원 중에 진실을 알고 있는 사람이 있으면
                flag = True
                break

        if flag:
            for attender in arr[i]: # 파티원 중 진실을 알고 있는 사람이 있는 파티의 다른 파티원까지 danger에 집어넣는다.
                danger[attender] = 1
            visited[i] = 1

    if danger_len == len(danger): # 더 이상 추가된 노드가 없을 때 종료
        break
    else:
        danger_len = len(danger)

# 전체 파티에서 danger들이 포함된, visited가 1인 파티를 빼면 답이다.
ans = 0
for i in range(m):
    ans += visited[i]

print(m - ans)