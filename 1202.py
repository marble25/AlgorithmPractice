# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 7.
# time : 오후 2:06
# problem : https://www.acmicpc.net/problem/1202
# problem type : Greedy

# 간단해 보이지만 꽤 까다로운 문제

import sys
from queue import PriorityQueue
n, k = map(int, sys.stdin.readline().split())

arr = []
for i in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))

# 배낭은 가격을 2000000으로 설정해서 배열에 넣음
for i in range(k):
    arr.append([int(sys.stdin.readline()), 2000000])

arr.sort()

sum = 0
q = PriorityQueue()
for x in arr:
    if x[1] != 2000000: # 보석인 경우
        q.put(-x[1]) # 내림차순 설정을 위해 음수 취함
    elif not q.empty(): # 가방인 경우
        sum += (-q.get()) # 우선순위 큐에서 가방 무게 이하인 보석 중 최대값을 꺼내옴
print(sum)