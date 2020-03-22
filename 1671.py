# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 20.
# time : 오후 12:16
# problem : https://www.acmicpc.net/problem/1671
# problem type : Network Flow

# 네트워크 플로우의 매운맛을 본 문제
# 나는 도저히 이런 방식의 풀이법을 생각해낼 자신이 없다.


def make_edge(here, there, weight):
    global linked, flow
    linked[here].append(there)
    linked[there].append(here)
    flow[here][there] += weight

import sys
from collections import deque
n = int(sys.stdin.readline())

linked = [[] for _ in range(2002)]
data = []
for i in range(n):
    data.append(list(map(int, sys.stdin.readline().split())))

flow = [[0] * 2002 for _ in range(2002)]

# source : 2n, sink : 2n+1
# 모든 상어들(2i)은 source에서 출발하고, 2i에 있는 상어가 2j+1의 상어를 잡아먹고, 2j+1이 sink로 흐른다.
for i in range(n):
    make_edge(2*n, 2*i, 2)
    make_edge(2*i+1, 2*n+1, 1)

    for j in range(n):
        if i == j: continue
        if data[i][0] < data[j][0] or data[i][1] < data[j][1] or data[i][2] < data[j][2]: continue # i가 j를 잡아먹을 수 없는 경우
        if data[i][0] == data[j][0] and data[i][1] == data[j][1] and data[i][2] == data[j][2] and i > j: continue # i와 j가 서로 잡아먹는 경우
        make_edge(2*i, 2*j+1, 1)

total = n
while True:
    parent = [-1] * 2002
    que = deque()
    que.appendleft(2*n)

    while len(que) > 0:
        here = que.pop()
        for there in linked[here]:
            if flow[here][there] > 0 and parent[there] == -1:
                parent[there] = here
                que.appendleft(there)

    if parent[2*n+1] == -1: break

    p = 2*n+1 # source에서
    while p != 2*n: # sink까지
        flow[parent[p]][p] -= 1 # 잡아먹었으면 하나씩 빼나감
        flow[p][parent[p]] += 1 # 반대방향으로는 더해감
        p = parent[p]

    total -= 1

print(total)