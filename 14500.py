# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 29.
# time : 오후 11:33
# problem : https://www.acmicpc.net/problem/14500
# problem type : Brute Force

# 테트로미노의 모든 모양을 저장한 후 모든 시작점에서 계산
tetrominos = [
    [(0, 0), (0, 1), (0, 2), (0, 3)], # 1자
    [(0, 0), (1, 0), (2, 0), (3, 0)], # 1자
    [(0, 0), (0, 1), (1, 0), (1, 1)], # 네모
    [(0, 0), (1, 0), (2, 0), (2, 1)], # ㄱ자
    [(0, 0), (1, 0), (1, 1), (1, 2)], # ㄱ자
    [(0, 0), (0, 1), (1, 1), (2, 1)], # ㄱ자
    [(0, 0), (0, 1), (0, 2), (1, 2)], # ㄱ자
    [(0, 1), (1, 1), (2, 0), (2, 1)], # ㄱ자
    [(0, 2), (1, 0), (1, 1), (1, 2)], # ㄱ자
    [(0, 0), (0, 1), (1, 0), (2, 0)], # ㄱ자
    [(0, 0), (0, 1), (0, 2), (1, 0)], # ㄱ자
    [(0, 0), (1, 0), (1, 1), (2, 1)], # 번개
    [(0, 1), (1, 0), (1, 1), (2, 0)], # 번개
    [(0, 1), (0, 2), (1, 0), (1, 1)], # 번개
    [(0, 0), (0, 1), (1, 1), (1, 2)], # 번개
    [(0, 0), (0, 1), (0, 2), (1, 1)], # ㅗ
    [(0, 1), (1, 0), (1, 1), (1, 2)], # ㅗ
    [(0, 1), (1, 0), (1, 1), (2, 1)], # ㅗ
    [(0, 0), (1, 0), (1, 1), (2, 0)]  # ㅗ
]

import sys
n, m = map(int, sys.stdin.readline().split())
arr = []
for i in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))

result = -1
for i in range(n):
    for j in range(m):
        for tetromino in tetrominos:
            sum = 0
            for k in range(4):
                x = tetromino[k][0]
                y = tetromino[k][1]

                # 배열 크기를 넘으면 계산 X
                if i + x >= n:
                    sum = -1
                    break
                if j + y >= m:
                    sum = -1
                    break

                sum += arr[i+x][j+y]

            result = max(result, sum)

print(result)