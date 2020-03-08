# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 8.
# time : 오후 10:35
# problem : https://www.acmicpc.net/problem/2644
# problem type : BFS

# 굉장히 간단한 BFS문제
# 촌수는 트리 구조를 띄기 때문에 a에서 b지점까지 최소 거리로 생각하면 된다.
from collections import deque

n = int(input())
start, end = map(int, input().split())

m = int(input())
linked = [[] for _ in range(n+1)]
visited = [0] * (n+1)
for i in range(m):
    x, y = map(int, input().split())
    linked[x].append(y)
    linked[y].append(x)

deq = deque()
deq.appendleft(start)
visited[start] = 1

while len(deq) > 0:
    x = deq.pop()
    for next_node in linked[x]:
        if visited[next_node] != 0:
            continue

        visited[next_node] = visited[x] + 1
        deq.appendleft(next_node)

if visited[end] == 0:
    print(-1)
else:
    print(visited[end] - 1)