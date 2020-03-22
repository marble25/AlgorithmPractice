# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 19.
# time : 오후 7:44
# problem : https://www.acmicpc.net/problem/15651
# problem type : Backtracking

# 가지치기도 필요없는 백트래킹 문제
# 이거는 완전탐색이 아닌가 싶다.
# 경로만 저장해서 출력해주면 끝

def f(stage, visited):
    if stage == m:
        print(' '.join(map(str, visited)))
        return

    for i in range(1, n+1):
        visited[stage] = i
        f(stage+1, visited)
        visited[stage] = 0

import sys
n, m = map(int, sys.stdin.readline().split())

f(0, [0] * m)