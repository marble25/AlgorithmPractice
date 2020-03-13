# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 13.
# time : 오후 1:08
# problem : https://www.acmicpc.net/problem/10707
# problem type : Simple

A = int(input())
B = int(input())
C = int(input())
D = int(input())
P = int(input())

x = P * A
y = B if P <= C else B + (P-C)*D
print(min(x, y))