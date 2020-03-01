# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 1.
# time : 오후 12:41
# problem : https://www.acmicpc.net/problem/15686
# problem type : Brute Force

# 모든 경우의 수를 파악하면 풀리는 문제
def distance(from_cords, to_cords):
    return abs(from_cords[0] - to_cords[0]) + abs(from_cords[1] - to_cords[1])

# f(index, maintain) : chicken집이 index 중 maintain만큼 있다
def f(index, maintain):
    global n, m
    global chickens, houses, visited
    global result
    if maintain == m: # 최대 m개이지만, m개를 채우는 것이 가장 유리하므로
        temp_result = 0
        for i in range(len(houses)):
            dist = 987654321
            for j in range(len(chickens)):
                if visited[j] == 1: # 폐업하지 않으면 거리를 최솟값 계산
                    dist = min(dist, distance(houses[i], chickens[j]))

            temp_result += dist
        result = min(temp_result, result)
        return
    if index == len(chickens): return # 치킨집 모두 순회했으면 리턴
    visited[index] = 1
    f(index + 1, maintain + 1)
    visited[index] = 0
    f(index + 1, maintain)

import sys

sys.setrecursionlimit(10000)

n, m = map(int, sys.stdin.readline().split())
houses = []
chickens = []
visited = [0] * 105
for i in range(n):
    input_line = list(map(int, sys.stdin.readline().split()))
    for j in range(n):
        if input_line[j] == 1:
            houses.append((i, j))
        elif input_line[j] == 2:
            chickens.append((i, j))

result = 987654321
f(0, 0)

print(result)