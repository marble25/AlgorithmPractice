# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 27.
# time : 오전 1:02
# problem : https://www.acmicpc.net/problem/1620
# problem type : Binary Search

import sys

n, m = map(int, sys.stdin.readline().split())
n2p, p2n = dict(), dict()
result = list()
for i in range(1, n+1):
    input_str = sys.stdin.readline().strip()
    n2p[i] = input_str
    p2n[input_str] = i

for i in range(m):
    input_str = sys.stdin.readline().strip()
    if input_str.isdigit():
        result.append(n2p[int(input_str)])
    else:
        result.append(p2n[input_str])

for i in range(m):
    print(result[i])