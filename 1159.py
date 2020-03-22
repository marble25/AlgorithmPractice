# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 24.
# time : 오후 9:40
# problem : https://www.acmicpc.net/problem/1159
# problem type : Basic

import sys

n = int(sys.stdin.readline())
s = []
for _ in range(n):
    s.append(sys.stdin.readline().strip())

result_list = [0] * 26
for i in range(n):
    result_list[ord(s[i][0]) - ord('a')] += 1

result = ''
flag = False
for i in range(26):
    if result_list[i] >= 5:
        result += chr(ord('a') + i)
        flag = True

if flag:
    print(result)
else:
    print('PREDAJA')