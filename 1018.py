# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 26.
# time : 오후 9:28
# problem : https://www.acmicpc.net/problem/1018
# problem type : Brute Force

import sys
n, m = map(int, sys.stdin.readline().split())

# 정답 체스판을 미리 저장
answer_board = [['WBWBWBWB', 'BWBWBWBW', 'WBWBWBWB', 'BWBWBWBW', 'WBWBWBWB', 'BWBWBWBW', 'WBWBWBWB', 'BWBWBWBW'],
                ['BWBWBWBW', 'WBWBWBWB', 'BWBWBWBW', 'WBWBWBWB', 'BWBWBWBW', 'WBWBWBWB', 'BWBWBWBW', 'WBWBWBWB']]
board = []
for _ in range(n):
    board.append(sys.stdin.readline().strip())


def check_chessboard(start_i, start_j, n, m, board, answer_board):
    var1 = 0
    var2 = 0
    for i in range(start_i, start_i + 8):
        for j in range(start_j, start_j + 8):
            if board[i][j] != answer_board[0][i-start_i][j-start_j]: # 첫 번째 체스판 모양과 다르면 var1 증가
                var1 += 1
            if board[i][j] != answer_board[1][i-start_i][j-start_j]: # 두 번째 체스판 모양과 다르면 var2 증가
                var2 += 1

    return min(var1, var2)

# 시작점을 순회해서 그 이후부터 8번째 칸까지 체스 판과 같은지 체크
answer = 987654321
for i in range(n-7):
    for j in range(m-7):
        answer = min(answer, check_chessboard(i, j, n, m, board, answer_board))

print(answer)