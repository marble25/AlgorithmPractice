# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 16.
# time : 오후 11:09
# problem : https://www.acmicpc.net/problem/9663
# problem type : Backtracking

# 백트래킹의 대표 문제이다.

def f(stage, visited):
    ret = 0
    checked = [True] * n
    if stage == n: # 끝까지 왔으면 1 리턴
        return 1

    for i in range(stage):
        checked[visited[i]] = False # 같은 열에 놓이지 않도록 체크
        right_bottom_dig = visited[i]-i+stage # 우하향 대각선 방향에 놓이지 않도록 체크
        if right_bottom_dig >= 0 and right_bottom_dig < n: checked[right_bottom_dig] = False
        right_up_dig = visited[i]+i-stage # 우상향 대각선 방향에 놓이지 않도록 체크
        if right_up_dig >= 0 and right_up_dig < n: checked[right_up_dig] = False

    for i in range(n):
        if checked[i]: # 가능하면 visited 업데이트하고 다음 행으로 떠남
            visited[stage] = i
            ret += f(stage+1, visited)

    return ret
import sys
n = int(sys.stdin.readline())
print(f(0, [0] * n))