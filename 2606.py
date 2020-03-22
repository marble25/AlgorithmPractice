# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 14.
# time : 오전 11:27
# problem : https://www.acmicpc.net/problem/2606
# problem type : BFS

# 완전 BFS 문제인데 Floyd-Warshall 문제라고 적혀져 있어서 이상했던 문제

import sys
from collections import deque

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
linked = [[] for _ in range(n+1)]
for _ in range(m):
    x, y = map(int, sys.stdin.readline().split())
    linked[x].append(y)
    linked[y].append(x)

deq = deque()
visited = [False for _ in range(n+1)]

deq.appendleft(1)
visited[1] = True

while len(deq) > 0:
    x = deq.pop()
    for next_node in linked[x]:
        if visited[next_node]: continue
        deq.appendleft(next_node)
        visited[next_node] = True

sum = 0
for i in range(1, n+1):
    if visited[i]: sum += 1

print(sum-1)