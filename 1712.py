# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 6.
# time : 오후 5:45
# problem : https://www.acmicpc.net/problem/1712
# problem type : Math

a, b, c = map(int, input().split())
if c <= b:
    x = -1
else:
    x = a / (c-b)
    x = int(x) + 1
print(x)
