# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 19.
# time : 오후 9:21
# problem : https://www.acmicpc.net/problem/2630
# problem type : Divide and Conquer

# 분할 정복으로 깔끔하게 풀어낸 문제
# 4분할로 나누어서 부분문제를 풀고, 4개 영역으로 종이 수를 센다.

def f(start_x, start_y, length):
    global white, blue
    if length == 1: # 길이 1일때 리턴
        return arr[start_x][start_y]

    areas = []
    areas.append(f(start_x, start_y, length // 2))
    areas.append(f(start_x + length // 2, start_y, length // 2))
    areas.append(f(start_x, start_y + length // 2, length // 2))
    areas.append(f(start_x + length // 2, start_y + length //2, length // 2))

    sum = areas[0] + areas[1] + areas[2] + areas[3] # 모든 파란 색종이의 수
    if sum != length ** 2 and sum != 0: # 파랑과 흰색이 섞여있으면
        for i in range(4):
            if areas[i] == (length // 2) ** 2: # 한 부분이 전부 파랑이면 파란 종이 ++
                blue += 1
            elif areas[i] == 0: # 한 부분이 전부 하양이면 흰 종이 ++
                white += 1
    return sum

import sys
sys.setrecursionlimit(10 ** 6)

n = int(sys.stdin.readline())
arr = []
for i in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))

white, blue = 0, 0
f(0, 0, n)
print(white)
print(blue)