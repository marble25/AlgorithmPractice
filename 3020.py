# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 10.
# time : 오후 3:29
# problem : https://www.acmicpc.net/problem/3020
# problem type : Binary Search

# Binary Search 문제 중 오랜만에 내 손으로 푼 문제
# 안틀리고 맞춰서 기분좋음

import sys
n, h = map(int, sys.stdin.readline().split())

A, B = [], []
for i in range(n):
    if i % 2 == 0:
        A.append(int(sys.stdin.readline())) # 석순
    else:
        B.append(int(sys.stdin.readline())) # 종유석

# A, B를 정렬해도 파괴해야 하는 장애물 갯수는 똑같음
A.sort()
B.sort()

arr_size = n // 2

min_val = 987654321
min_cnt = 0

past_a_index = 0
past_b_index = arr_size - 1

for a_height in range(1, h+1):
    a_result = 0
    b_result = arr_size

    b_height = h+1-a_height

    for i in range(past_a_index, arr_size):
        if A[i] >= a_height: # 부딪히는 순간
            a_result = arr_size - i # A[i]보다 크거나 같은 석순 갯수
            past_a_index = i
            break

    for i in range(past_b_index, -1, -1):
        if B[i] < b_height: # 안부딪히는 순간
            b_result = arr_size - i - 1 # B[i]보다 크거나 같은 종유석 갯수
            past_b_index = i
            break

    # min_val과 min_cnt 업데이트 시킴
    if a_result + b_result < min_val:
        min_val = a_result + b_result
        min_cnt = 1
    elif a_result + b_result == min_val:
        min_cnt += 1

print(min_val, min_cnt)