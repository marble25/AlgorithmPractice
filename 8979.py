# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 13.
# time : 오후 1:12
# problem : https://www.acmicpc.net/problem/8979
# problem type : Simple

import sys
n, m = map(int, sys.stdin.readline().split())
l = []
for _ in range(n):
    idx, gold, silver, bronze = map(int, sys.stdin.readline().split())
    l.append([gold, silver, bronze, idx])
    if idx == m:
        country = [gold, silver, bronze, idx]

count = 1
for i in range(n):
    if l[i][3] == country[3]: continue
    if l[i][0] > country[0]: count += 1
    elif l[i][0] == country[0] and l[i][1] > country[1]: count += 1
    elif l[i][0] == country[0] and l[i][1] == country[1] and l[i][2] > country[2]: count += 1

print(count)