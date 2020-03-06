# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 6.
# time : 오후 6:48
# problem : https://www.acmicpc.net/problem/10569
# problem type : Math

import sys
T = int(sys.stdin.readline())

for i in range(T):
    v, e = map(int, sys.stdin.readline().split())
    print(e-v+2)