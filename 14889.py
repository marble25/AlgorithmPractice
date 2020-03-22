# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 26.
# time : 오후 6:27
# problem : https://www.acmicpc.net/problem/14889
# problem type : Brute Force

import sys

n = int(sys.stdin.readline())
s = []
team = [0] * n # 0과 1로 된 팀 배열
for i in range(n):
    s.append(list(map(int, sys.stdin.readline().split())))

def calculate_score(team, n, s):
    score = 0
    for i in range(len(team)):
        for j in range(len(team)):
            score += s[team[i]][team[j]]

    return score

# 능력치의 차를 구해주는 함수
def check_ability(team, n, s):
    team1 = []
    team2 = []
    for i in range(n):
        if team[i] == 1:
            team1.append(i)
        else:
            team2.append(i)

    team1_score = calculate_score(team1, n, s)
    team2_score = calculate_score(team2, n, s)

    return abs(team1_score - team2_score)

# n/2번 반복
def f(team, stage, x, n, s):
    ret = 987654321
    if stage == n // 2: return check_ability(team, n, s)
    for i in range(x+1, n):
        team[i] = 1
        ret = min(ret, f(team, stage+1, i, n, s)) # 다음 스테이지로 넘어감
        team[i] = 0

    return ret

print(f(team, 0, -1, n, s))