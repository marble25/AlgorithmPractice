# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 13.
# time : 오후 3:22
# problem : https://www.acmicpc.net/problem/10984
# problem type : Simple

import sys

T = int(sys.stdin.readline())
for _ in range(T):
    n = int(sys.stdin.readline())
    sum = 0
    result = 0
    for i in range(n):
        x, y = map(float, sys.stdin.readline().split())
        result += x * y
        sum += x
    print(int(sum), result / sum)