# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 20.
# time : 오전 11:12
# problem : https://www.acmicpc.net/problem/6086
# problem type : Network Flow

# 에드몬드 카프 알고리즘을 이용한 기본적인 네트워크 플로우 문제이다.
# 새로운 알고리즘을 배웠으니 많은 문제를 풀어봐야겠다.

def char2int(character):
    if ord('A') <= ord(character) <= ord('Z'):
        character = ord(character) - ord('A')
    elif ord('a') <= ord(character) <= ord('z'):
        character = ord(character) - ord('a') + 26
    return character

def residual(here, there): # 용량에서 현재 흐른 유량을 빼서 잔여 유량을 구해줌
    return capacity[here][there] - flow[here][there]

import sys
from collections import deque
n = int(sys.stdin.readline())

capacity = [[0] * (55) for _ in range(55)]
flow = [[0] * (55) for _ in range(55)]

for i in range(n):
    x, y, c = sys.stdin.readline().split()
    x, y = char2int(x), char2int(y)
    c = int(c)

    capacity[x][y] += c # 더해주는 이유는 같은 경로에 여러 개 들어올 수 있으므로
    capacity[y][x] += c

que = deque()
total = 0

while True:
    parent = [-1] * (55)
    parent[0] = 0
    que.appendleft(0)

    while len(que) > 0:
        here = que.pop()
        for there in range(52):
            if residual(here, there) > 0 and parent[there] == -1: # 잔여 유량이 있고 방문하지 않은 점일 때
                parent[there] = here # 부모 노드 저장
                que.appendleft(there)

    if parent[25] == -1: break # Z까지 연결이 되지 않으면 break

    min_num = 987654321
    p = 25
    while p != 0:
        min_num = min(capacity[parent[p]][p] - flow[parent[p]][p], min_num) # 지금 탐색한 경로에서 흐를 수 있는 유량의 최솟값을 min_num에 저장
        p = parent[p]

    p = 25
    while p != 0:
        flow[parent[p]][p] += min_num # 현재 흐른 최소 유량을 더해줌
        flow[p][parent[p]] -= min_num # 반대 방향으로 흐른 최소 유량을 더해줌

        p = parent[p]

    total += min_num

print(total)