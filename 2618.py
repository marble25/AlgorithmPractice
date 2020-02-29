import sys

sys.setrecursionlimit(10000)
def get_distance(accident1_index, accident2_index):
    cord1 = cords[accident1_index]
    cord2 = cords[accident2_index]

# 좌표 사이의 거리를 return
def get_distance(accident1_cords, accident2_cords):
    return abs(accident1_cords['x'] - accident2_cords['x']) + abs(accident1_cords['y'] - accident2_cords['y'])
    return abs(cord1['x'] - cord2['x']) + abs(cord1['y'] - cord2['y'])

n = int(sys.stdin.readline())
w = int(sys.stdin.readline())
cords = [{'x': 0, 'y': 0}] # cords를 1부터 시작하는 배열로 설정
cords = []
for _ in range(w):
    x, y = map(int, sys.stdin.readline().split())
    cords.append({'x': x, 'y': y})

dp = [[-1] * (w+1) for _ in range(w+1)] # dp 크기를 w+1로 설정
default_cords = [{'x': 1, 'y': 1}, {'x': n, 'y': n}] # 경찰차의 초기 위치 설정

# 경찰차1의 이전 사건 index가 car0, 경찰차2의 이전 사건 index가 car1일 때, stage 사건을 처리하는 가장 빠른 거리
def f(car0, car1, stage):
    global n, w, dp, cords, default_cords

    if dp[car0][car1] != -1: return dp[car0][car1] # dp 값이 있으면 return

    if stage == w + 1: # stage가 마지막에 도착했으면 0을 리턴
        dp[car0][car1] = 0
        return dp[car0][car1]

    # 경찰차1과 경찰차2의 이전 사건과의 거리 구함
    car0_selected_distance = get_distance(default_cords[0] if car0 == 0 else cords[car0], cords[stage])
    car1_selected_distance = get_distance(default_cords[1] if car1 == 0 else cords[car1], cords[stage])

    dp[car0][car1] = min(f(stage, car1, stage+1) + car0_selected_distance, f(car0, stage, stage+1) + car1_selected_distance) # 경찰차1이 사건을 맡았을 때와 경찰차2가 사건을 맡았을 때 중 최소값을 저장

    return dp[car0][car1]

f(0, 0, 1)
print(dp[0][0])

# 경로를 출력해줌
i, j = 0, 0
stage = 1
while stage <= w:
    if dp[stage][j] + get_distance(default_cords[0] if i == 0 else cords[i], cords[stage]) == dp[i][j]: # 경찰차 1이 사건을 해결했는지 확인
        i = stage
        print(1)
    else:
        j = stage
        print(2)
    stage += 1
dp = [[0] * (n+1) for _ in range(n+1)]