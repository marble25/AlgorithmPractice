# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 9.
# time : 오전 11:16
# problem : https://www.acmicpc.net/problem/1014
# problem type : Bipartite Graph

# 쉬워보였지만 상당히 어려운 문제
# 문제 해법을 찾아보니 이분 그래프라는 것이 있었고, 새로운 알고리즘을 습득했다.

import sys
sys.setrecursionlimit(1000000)
C = int(sys.stdin.readline())

def dfs(x):
    global bimap, matched, visited
    if visited[x]: return False
    visited[x] = True
    for y, linked in enumerate(bimap[x]):
        if linked: # 연결되어 있다면
            if y not in matched or dfs(matched[y]): # 현재 y가 matched에 없거나 연결된 x를 타고 올라간 값의 y가 matched에 없으면 matched에 추가하고 True return
                matched[y] = x
                return True
    return False

for _ in range(C):
    N, M = map(int, sys.stdin.readline().split())
    arr = [[0] * M for _ in range(N)]
    visited = [[0] * M for _ in range(N)]
    sit_cnt = 0
    for i in range(N):
        input_str = sys.stdin.readline().strip()
        for j in range(M):
            if input_str[j] == '.': # 앉을 수 있는 자리라면
                arr[i][j] = 1
                sit_cnt += 1 # sit_cnt 증가

    matched = {}

    # X : 짝수 열, Y : 홀수 열로 새로운 dict를 만든다.
    # X(x좌표, y좌표) = (노드 index, 앉을 수 있는지)
    X = {}
    Y = {}
    x_index = 0
    y_index = 0

    for i in range(M):
        for j in range(N):
            if i % 2 == 0:
                X[(j, i)] = (x_index, arr[j][i])
                x_index += 1
            else:
                Y[(j, i)] = (y_index, arr[j][i])
                y_index += 1

    # 서로 컨닝할 수 있는 노드들을 연결한다.
    bimap = [[0] * (N*M) for _ in range(N*M)]
    for x, y in X:
        item = X[(x, y)]
        if item[1] == 0: # 앉을 수 없다면 continue
            continue

        candidates = [(x-1, y-1), (x, y-1), (x+1, y-1), (x-1, y+1), (x, y+1), (x+1, y+1)]
        for cx, cy in candidates:
            if cx < 0 or cx >= N: continue # x 범위 체크
            if cy < 0 or cy >= M: continue # y 범위 체크
            if arr[cx][cy] == 0: continue # 앉을 수 있는지 체크

            # node index를 가져옴
            bi_x = X[(x, y)][0]
            bi_y = Y[(cx, cy)][0]

            bimap[bi_x][bi_y] = 1

    # X의 모든 노드에 대해 dfs
    for i in range(len(X)):
        visited = [False for _ in range(len(X))]
        dfs(i)

    result = sit_cnt - len(matched)
    print(result)