# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 18.
# time : 오전 10:56
# problem : https://www.acmicpc.net/problem/3980
# problem type : Bitmask, Brute Force

# 모든 경우를 탐색하면서 가능하지 않은 경우를 제외해주면서 탐색하면 쉬운 문제

def dfs(stage, visited):
    global max_val
    if stage == 11:
        res = 0
        for i in range(0, 11):
            if visited[i] == -1: # 포지션이 할당죄아 않은 사람이 있다면 리턴
                return
            res += visited[i]

        max_val = max(max_val, res)
        return
    for i in range(0, 11):
        if arr[stage][i] != 0 and visited[i] == -1: # 포지션 점수가 0이 아니고, 그 포지션에 할당된 사람이 없다면
            visited[i] = arr[stage][i] # visited에 추가하고 다음 사람으로 넘어감
            dfs(stage+1, visited)
            visited[i] = -1 # visited 초기화

import sys
sys.setrecursionlimit(10 ** 6)
T = int(sys.stdin.readline())

for _ in range(T):
    arr = []
    for i in range(11):
        arr.append(list(map(int, sys.stdin.readline().split())))
    visited = [-1] * 11
    max_val = -1
    dfs(0, visited)
    print(max_val)