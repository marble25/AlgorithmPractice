# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 6.
# time : 오후 7:33
# problem : https://www.acmicpc.net/problem/1072
# problem type : Math

# 수학적 공식으로 계산해서 맞춤
# 이진 탐색으로 푸는 방법도 있음
import math

x, y = map(int, input().split())
n = int(100 * y // x)
if n >= 99:
    print(-1)
    exit()

result = math.ceil(((n+1) * x - 100 * y) / (99 - n))

print(result)