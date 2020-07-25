# project : baekjoon python algorithm practice
# user : marble
# date : 20. 7. 25.
# time : 오전 00:11
# problem : https://www.acmicpc.net/problem/2226
# problem type : Math

# c++로 풀려 했으나 큰수 구현이 너무 귀찮아서 파이썬으로 오랜만에 풀었다.

import sys
n = int(sys.stdin.readline())

if n == 1: print(0)
elif n == 2: print(1)
else:
    ans = 1
    for i in range(3, n+1):
        if i % 2 == 1:
            ans = ans * 2 - 1
        else:
            ans = ans * 2 + 1

    print(ans)
