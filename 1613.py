# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 16.
# time : 오후 10:48
# problem : https://www.acmicpc.net/problem/1613
# problem type : Floyd-Warshall, BFS

# 아주 기초적인 Floyd-Warshall 문제
# BFS로도 풀 수 있지만, Floyd-Warshall 연습하느라 이 방법으로 풂

import sys
n, k = map(int, sys.stdin.readline().split())
linked = [[987654321] * (n+1) for _ in range(n+1)]
for i in range(k):
    x, y = map(int, sys.stdin.readline().split())
    linked[x][y] = 1

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if linked[i][j] > linked[i][k] + linked[k][j]: # k를 거쳐가는 것이 더 짧을 때 update
                linked[i][j] = linked[i][k] + linked[k][j]

s = int(sys.stdin.readline())
for i in range(s):
    x, y = map(int, sys.stdin.readline().split())
    if linked[x][y] != 987654321: print(-1) # 값이 있으면 역사적 선후관계가 있음
    elif linked[y][x] != 987654321: print(1)
    else: print(0)