# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 8.
# time : 오후 10:50
# problem : https://www.acmicpc.net/problem/1389
# problem type : BFS

# 간단한 BFS 문제
# 모든 정점에 대해 BFS를 돌려서 거리 합이 가장 작게 나오는 정점 번호 출력

import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
linked = [[] for _ in range(n+1)]

for i in range(m):
    x, y = map(int, sys.stdin.readline().split())
    linked[x].append(y)
    linked[y].append(x)

min_sum = 987654321
min_index = 0
for i in range(1, n+1):
    deq = deque()
    visited = [0] * (n+1)

    deq.appendleft(i)
    visited[i] = 1
    sum = 0
    while len(deq) > 0:
        x = deq.pop()
        for next_node in linked[x]:
            if visited[next_node] != 0: continue

            visited[next_node] = visited[x] + 1
            deq.appendleft(next_node)
            sum += visited[x]

    if sum < min_sum:
        min_sum = sum
        min_index = i

print(min_index)