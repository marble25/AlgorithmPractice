# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 16.
# time : 오후 10:18
# problem : https://www.acmicpc.net/problem/10159
# problem type : Floyd-Warshall, BFS

# 2458 문제랑 거의 똑같은 문제
# 이번에는 BFS가 아닌, Floyd-Warshall로 풀어보았다.
# 시간복잡도는 더 안좋게 나오는 것 같다.

import sys
n = int(input())
m = int(input())

linked = [[987654321] * (n+1) for _ in range(n+1)]
for i in range(m):
    x, y = map(int, sys.stdin.readline().split())
    linked[x][y] = 1

# 경로를 구할 수 있는 것들을 모두 구함
for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if linked[i][j] > linked[i][k] + linked[k][j]: # i와 j 사이에 k 정점을 거쳐가는 것이 linked[i][j]보다 작으면 업데이트
                linked[i][j] = linked[i][k] + linked[k][j]

for i in range(1, n+1):
    count = 0
    for j in range(1, n+1):
        if linked[i][j] != 987654321 or linked[j][i] != 987654321: # 반대 경로는 linked[j][i]로 되었을 테니 둘다 연결이 안되어 있다면 i와 j는 연결되지 않은 노드이다.
            count += 1

    print(n-1 - count)