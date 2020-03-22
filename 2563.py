# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 7.
# time : 오후 8:43
# problem : https://www.acmicpc.net/problem/2563
# problem type : simple

paper = [[0] * 100 for _ in range(100)]

# 색종이가 있는 부분을 도화지에서 채우기
n = int(input())
for i in range(n):
    x, y = map(int, input().split())
    for j in range(x, min(x+10, 100)): # 색종이가 넘어가는 경우 그 부분을 빼고 생각
        for k in range(y, min(y+10, 100)):
            paper[j][k] = 1

sum = 0
for i in range(100):
    for j in range(100):
        sum += paper[i][j]

print(sum)