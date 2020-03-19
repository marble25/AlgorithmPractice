# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 19.
# time : 오후 7:40
# problem : https://www.acmicpc.net/problem/15650
# problem type : Backtracking

# 매우 간단한 백트래킹 문제
# 현재값보다 더큰 경우에 대해서만 탐색을 진행하면 됨

def f(stage, x, visited):
    if stage == m:
        print(' '.join(map(str, visited)))
        return

    for i in range(x+1, n+1):
        visited[stage] = i
        f(stage+1, i, visited)
        visited[stage] = 0


import sys
n, m = map(int, sys.stdin.readline().split())

f(0, 0, [0] * m)