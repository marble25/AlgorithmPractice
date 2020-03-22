# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 29.
# time : 오후 2:53
# problem : https://www.acmicpc.net/problem/2666
# problem type : DP

# 배열 크기로 인한 런타임 에러가 많이 발생
# 배열 크기를 늘렸더니 해결했지만 아직 왜 크기 때문에 런타임 에러가 났는지 모르겠
import sys

sys.setrecursionlimit(1000010)
n = int(sys.stdin.readline())
x, y = map(int, sys.stdin.readline().split())

m = int(sys.stdin.readline())
order = [0]
for i in range(m):
    order.append(int(sys.stdin.readline()))

# dp[i][j] : 문 1은 가장 최근에 사용할 벽장 중 i번째 index로 이동했고, 문2는 j번째 index로 이동했을 때 문이 이동한 최소 횟수
dp = [[-1] * (30) for _ in range(30)]

def f(door1_index, door2_index, stage):
    global x, y, n, m, order, dp

    if stage == m: return 0
    if dp[door1_index][door2_index] != -1: return dp[door1_index][door2_index]

    # door_index에서 문의 위치를 알아냄
    door1_pos = x if door1_index == 0 else order[door1_index]
    door2_pos = y if door2_index == 0 else order[door2_index]

    # door_pos에서 지금 사용할 벽장 문까지의 거리를 알아냄
    door1_distance = abs(order[stage+1] - door1_pos)
    door2_distance = abs(order[stage+1] - door2_pos)

    # dp는 문1을 사용하는 경우와 문2를 사용하는 경우의 최솟값을 저장
    dp[door1_index][door2_index] = min(f(stage+1, door2_index, stage+1) + door1_distance, f(door1_index, stage+1, stage+1) + door2_distance)
    return dp[door1_index][door2_index]

print(f(0, 0, 0))