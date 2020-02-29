# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 24.
# time : 오후 7:23
# problem : https://www.acmicpc.net/problem/2618
# problem type : DP

import sys

sys.setrecursionlimit(10000)

def get_distance(accident1_cords, accident2_cords):
    return abs(accident1_cords['x'] - accident2_cords['x']) + abs(accident1_cords['y'] - accident2_cords['y'])

n = int(sys.stdin.readline())
w = int(sys.stdin.readline())
cords = [{'x': 0, 'y': 0}]
for _ in range(w):
    x, y = map(int, sys.stdin.readline().split())
    cords.append({'x': x, 'y': y})

dp = [[-1] * (w+1) for _ in range(w+1)]
default_cords = [{'x': 1, 'y': 1}, {'x': n, 'y': n}]

def f(car0, car1, stage):
    global n, w, dp, cords, default_cords

    if dp[car0][car1] != -1: return dp[car0][car1]

    if stage == w + 1:
        dp[car0][car1] = 0
        return dp[car0][car1]

    car0_selected_distance = get_distance(default_cords[0] if car0 == 0 else cords[car0], cords[stage])
    car1_selected_distance = get_distance(default_cords[1] if car1 == 0 else cords[car1], cords[stage])

    dp[car0][car1] = min(f(stage, car1, stage+1) + car0_selected_distance, f(car0, stage, stage+1) + car1_selected_distance)

    return dp[car0][car1]

f(0, 0, 1)
print(dp[0][0])

i, j = 0, 0
stage = 1
while stage <= w:
    if dp[stage][j] + get_distance(default_cords[0] if i == 0 else cords[i], cords[stage]) == dp[i][j]:
        i = stage
        print(1)
    else:
        j = stage
        print(2)
    stage += 1
