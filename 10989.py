# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 1.
# time : 오후 2:36
# problem : https://www.acmicpc.net/problem/10989
# problem type : Sort

# pypy로 제출했더니 메모리 초과 뜬 문제
# 기수 정렬로 푸니 간단하게 맞음

import sys
arr = [0] * 10005
n = int(sys.stdin.readline())
for i in range(n):
    x = int(sys.stdin.readline())
    arr[x] += 1

for i in range(1, 10001):
    for j in range(arr[i]):
        print(i)