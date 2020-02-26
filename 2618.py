# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 24.
# time : 오후 7:23
# problem : https://www.acmicpc.net/problem/2618
# problem type : DP

import sys

def get_distance(accident1_index, accident2_index):
    cord1 = cords[accident1_index]
    cord2 = cords[accident2_index]

    return abs(cord1['x'] - cord2['x']) + abs(cord1['y'] - cord2['y'])

n = int(sys.stdin.readline())
w = int(sys.stdin.readline())
cords = []
for _ in range(w):
    x, y = map(int, sys.stdin.readline().split())
    cords.append({'x': x, 'y': y})

dp = [[0] * (n+1) for _ in range(n+1)]
