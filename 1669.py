# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 19.
# time : 오후 2:43
# problem : https://www.acmicpc.net/problem/1669
# problem type : DP

# n이 0일 때에도 생각해 주어야 하는 문제이다.
# 12321, 1234321 꼴이 최소이고, 이를 초과하는 값은 중간중간에 적절한 값을 끼워 넣으면 된다.

import sys
import math
x, y = map(int, sys.stdin.readline().split())
n = y-x
sqrt_x = int(math.sqrt(n))

# 차이가 0일 때를 따로 빼서 출력
if n == 0:
    print(0)
    sys.exit(0)

n -= sqrt_x ** 2
days = sqrt_x * 2 - 1 # 12321 꼴로 맞춰주는데 필요한 날을 더해줌
for i in range(sqrt_x, 0, -1):
    if n >= i: # 이 수열에 i를 추가로 넣을 수 있으면 넣고 n에서 빼줌
        n -= i
        days += 1

print(days)