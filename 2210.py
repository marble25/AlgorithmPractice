# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 19.
# time : 오후 8:41
# problem : https://www.acmicpc.net/problem/2210
# problem type : Backtracking

# 그냥 완전탐색 돌리면서 끝에 경로만 숫자로 만들어서 저장해 주면 되는 문제

def f(stage, x, y, visited):
    global check
    if stage == 6:
        num = ''.join(map(str, visited))
        check[num] = 1
        return

    visited[stage] = arr[x][y]
    if x+1 < 5:
        f(stage+1, x+1, y, visited)
    if y+1 < 5:
        f(stage+1, x, y+1, visited)
    if x-1 >= 0:
        f(stage+1, x-1, y, visited)
    if y-1 >= 0:
        f(stage+1, x, y-1, visited)
    visited[stage] = 0
import sys
arr = []
for i in range(5):
    arr.append(list(map(int, sys.stdin.readline().split())))

check = {}
for i in range(5):
    for j in range(5):
        f(0, i, j, [0] * 6)

print(len(check))