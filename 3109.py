# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 7.
# time : 오후 11:23
# problem : https://www.acmicpc.net/problem/3109
# problem type : Backtracking, Greedy

# 실제 대회 TC를 넣어봐서 오류를 찾은 문제

import sys
sys.setrecursionlimit(1000000)

R, C = map(int, sys.stdin.readline().split())

bread_map = []
for i in range(R):
    input_str = sys.stdin.readline().strip()
    bread_map.append([1 if element == 'x' else 0 for element in input_str]) # x를 1로, .을 0으로 바꿔줌

def f(row, column):
    global bread_map
    bread_map[row][column] = 1 # 방문한 노드값을 1로 설정(다시 안올 수 있게)

    if column == C-1:
        return 1
    if row-1 >= 0 and bread_map[row-1][column+1] == 0: # 우측 상단
        ret = f(row-1, column+1)
        if ret == 1: return ret
    if row >= 0 and bread_map[row][column+1] == 0: # 우측 중앙
        ret = f(row, column + 1)
        if ret == 1: return ret
    if row+1 < R and bread_map[row+1][column+1] == 0: # 우측 하단
        ret = f(row+1, column + 1)
        if ret == 1: return ret

    return 0

# 0~R-1 줄에서 시작해서 끝까지 도달할 수 있으면 1, 아니면 0
count = 0
for i in range(R):
    count += f(i, 0)

print(count)