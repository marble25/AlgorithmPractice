# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 7.
# time : 오후 9:17
# problem : https://www.acmicpc.net/problem/2567
# problem type : simple

paper = [[0] * 101 for _ in range(101)]

# 색종이가 있는 부분을 도화지에서 채우기
n = int(input())
for i in range(n):
    x, y = map(int, input().split())
    for j in range(x, min(x+10, 100)): # 색종이가 넘어가는 경우 그 부분을 빼고 생각
        for k in range(y, min(y+10, 100)):
            paper[j][k] = 1

# 현 위치가 1이고, 상하좌우 중 0인 곳이 있으면 하나씩 더해줌
side = 0
for i in range(1, 100):
    for j in range(1, 100):
        if paper[i][j] == 0: continue
        if paper[i+1][j] == 0: side += 1
        if paper[i-1][j] == 0: side += 1
        if paper[i][j+1] == 0: side += 1
        if paper[i][j-1] == 0: side += 1

print(side)
