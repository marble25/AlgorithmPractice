# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 19.
# time : 오후 7:30
# problem : https://www.acmicpc.net/problem/15649
# problem type : Backtracking

# 간단한 백트래킹 문제
# 경로와 선택한 값들을 변수로 보내서 체크하고 이미 체크한 value들은 가지치기

def f(stage, visited, checked):
    if stage == m:
        print(' '.join(map(str, visited)))
        return

    for i in range(1, n+1):
        if not checked[i]:
            checked[i] = True
            visited[stage] = i
            f(stage+1, visited, checked)
            checked[i] = False
            visited[stage] = 0

import sys
n, m = map(int, sys.stdin.readline().split())

f(0, [0] * m, [False] * (n+1))
