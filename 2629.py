# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 27.
# time : 오후 9:16
# problem : https://www.acmicpc.net/problem/2629
# problem type : DP

import sys
from collections import deque

n = int(sys.stdin.readline())
weights = list(map(int, sys.stdin.readline().split()))

m = int(sys.stdin.readline())
marble_weights = list(map(int, sys.stdin.readline().split()))

available_weights = [0] * 40005

# 가장 마지막에 있는 값을 넣고 시작
available_weights[weights[n-1]] = 1
for i in range(n-2, -1, -1):
    # Queue에 있는 값으로 체크(Queue에 넣지 않으면 같은 값을 중복으로 체크할 수 있음)
    queue = deque()
    for j in range(40001):
        if available_weights[j] == 1: queue.append(j)

    # Queue에 있는 모든 값들을 대상으로 현재값 플러스 마이너스한 결과를 available_weights애 넣음
    while len(queue) > 0:
        weight = queue.pop()
        if abs(weight - weights[i]) > 0: # abs 체크하는 것 중요! abs 체크 안해서 한번 틀림
            available_weights[abs(weight - weights[i])] = 1
        if weight + weights[i] <= 40000:
            available_weights[weight + weights[i]] = 1
    available_weights[weights[i]] = 1

result_str = ''
for i in range(m):
    if available_weights[marble_weights[i]] == 1:
        result_str += 'Y '
    else:
        result_str += 'N '

print(result_str)