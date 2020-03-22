# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 13.
# time : 오후 3:13
# problem : https://www.acmicpc.net/problem/2935
# problem type : Simple

# 굉장히 간단한 방법(Python이라 가능)
#
# A = int(input())
# B = input().strip()
# C = int(input())
# if B == '+':
#     print(A+C)
# elif B == '*':
#     print(A*C)

# 문제가 의도하던 풀이법
A = input().strip()
B = input().strip()
C = input().strip()

log_a = len(A)-1
log_b = len(C)-1

s = ''
if B == '+':
    if log_a == log_b:
        s += '2' + '0' * log_a
    else:
        s += '1' + '0' * (abs(log_a-log_b)-1) + '1' + '0' * min(log_a, log_b)
else:
    s += '1' + '0' * (log_a + log_b)

print(s)