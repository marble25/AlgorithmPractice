# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 15.
# time : 오후 5:42
# problem : https://www.acmicpc.net/problem/5214
# problem type : BFS

# Tube라는 개념이 있어서 BFS 생각해내기 살짝 까다로웠던 문제

import sys
from collections import deque
n, k, m = map(int, sys.stdin.readline().split())
linked = [[] for _ in range(n+1)]
tubes = []
for i in range(m):
    group = list(map(int, sys.stdin.readline().split()))
    tubes.append(group)

    for station in group:
        linked[station].append(i)

visited = [987654321] * (n+1)

que = deque()
for start_tube in linked[1]:
    que.appendleft((1, start_tube)) # 1번 역이 속해있는 tube들을 모두 같이 넣어줌
visited[1] = 1

while len(que) > 0:
    station, tube = que.pop()

    for next_station in tubes[tube]:
        if visited[next_station] != 987654321: continue # 이미 방문한 역이면 continue

        if visited[next_station] > visited[station] + 1: # 다음 역까지 거리가 현재 역에서 1 더한 것보다 클 때 업데이트
            visited[next_station] = visited[station] + 1

            for next_tube in linked[next_station]: # 다음 역이 연결되어 있는 튜브들을 모두 큐에 넣어줌
                if next_tube == tube: continue # 현재 큐브이면 continue

                que.appendleft((next_station, next_tube))

print(visited[n] if visited[n] != 987654321 else -1)