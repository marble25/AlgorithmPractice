# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 17.
# time : 오후 1:25
# problem : https://www.acmicpc.net/problem/2580
# problem type : Backtracking

# arr[x][y]가 어차피 바뀌므로 0으로 안바꿔줘도 되겠다고 생각해서 한번 틀렸던 문제
# 그래도 백트래킹 문제를 풀어가는 재미가 있다.

def dfs(stage, arr):
    checked = [0] * 10 # 이미 존재하는 숫자들을 체크할 배열
    if stage == len(blanks): # 모든 0을 다 채웠따면 출력하고 프로그램 종료
        for i in range(9):
            print(' '.join(map(str, arr[i])))
        sys.exit(0)
    x = blanks[stage][0]
    y = blanks[stage][1]
    box_start = ((x // 3) * 3, (y // 3) * 3) # 3*3 박스의 시작점
    for i in range(9):
        checked[arr[i][y]] = 1 # 세로줄 체크
        checked[arr[x][i]] = 1 # 가로줄 체크
        checked[arr[box_start[0] + i // 3][box_start[1] + i % 3]] = 1 # 박스 체크

    for i in range(1, 10):
        if checked[i] == 0:
            arr[x][y] = i # arr 값 바꾸고 dfs 진행
            dfs(stage+1, arr)
            arr[x][y] = 0



import sys
sys.setrecursionlimit(10 ** 9)
arr = [[0] * 9 for _ in range(9)]
blanks = []
for i in range(9):
    arr[i] = list(map(int, sys.stdin.readline().split()))
    for j in range(9):
        if arr[i][j] == 0:
            blanks.append((i, j))

if len(blanks) != 0:
    dfs(0, arr)
else: # 0이 하나도 없으면 그 값 그대로 출력
    for i in range(9):
        print(' '.join(map(str, arr[i])))