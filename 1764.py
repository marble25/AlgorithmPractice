# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 7.
# time : 오후 8:35
# problem : https://www.acmicpc.net/problem/1764
# problem type : simple

import sys
n, m = map(int, sys.stdin.readline().split())

d = dict()
for i in range(n):
    input_str = sys.stdin.readline().strip()
    d[input_str] = 1

count = 0
result = []
for i in range(m):
    input_str = sys.stdin.readline().strip()
    if input_str in d:
        count += 1
        result.append(input_str)

result.sort()
print(count)
for i in range(count):
    sys.stdout.write(result[i] + '\n')