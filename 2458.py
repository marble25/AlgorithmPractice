# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 16.
# time : 오후 10:01
# problem : https://www.acmicpc.net/problem/2458
# problem type : Floyd-Warshall, BFS

# start점에서 link배열을 인접 리스트로 삼는 bfs를 돌림, 연결되는 노드 갯수 count해서 리턴
def bfs(start, link):
    visited = [False for _ in range(n + 1)]
    que = deque()
    count = 0

    visited[start] = True
    que.appendleft(start)

    while len(que) > 0:
        x = que.pop()
        for next_node in link[x]:
            if visited[next_node]: continue
            que.appendleft(next_node)
            visited[next_node] = True
            count += 1

    return count

import sys
from collections import deque
n, m = map(int, sys.stdin.readline().split())
linked = [[] for _ in range(n+1)]
linked_inv = [[] for _ in range(n+1)]
for i in range(m):
    x, y = map(int, sys.stdin.readline().split())
    linked[x].append(y)
    linked_inv[y].append(x) # 반대로 가는 경로도 저장

results = [[-1, -1] for _ in range(n+1)]
ans = 0

for i in range(1, n+1):
    results[i][0] = bfs(i, linked)
    results[i][1] = bfs(i, linked_inv)
    if results[i][0] + results[i][1] == n-1: ans += 1 # 자기보다 큰 사람과 자기보다 작은 사람이 합쳐서 n-1이 되면 답을 더해줌

print(ans)


