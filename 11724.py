# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 1.
# time : 오후 2:20
# problem : https://www.acmicpc.net/problem/11724
# problem type : BFS

# BFS를 이용하면 간단히 풀리는 문제
import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
linked = []
visited = [-1] * (n+1)
count = 0
for i in range(n+1):
    linked.append([])

for i in range(m):
    x, y = map(int, sys.stdin.readline().split())
    linked[x].append(y)
    linked[y].append(x)

queue = deque()
for i in range(1, n+1):
    if visited[i] != -1: continue # 이미 그룹핑 되어있다면 continue
    count += 1 # 새로운 그룹에 대해서 BFS로 연결된 노드 모두 찾기
    queue.append(i)
    visited[i] = 1
    while len(queue) > 0:
        x = queue.pop()
        for next_node in linked[x]:
            if visited[next_node] == -1:
                queue.append(next_node)
                visited[next_node] = 1

print(count)