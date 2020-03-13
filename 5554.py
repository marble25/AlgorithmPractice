# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 13.
# time : 오후 3:06
# problem : https://www.acmicpc.net/problem/5554
# problem type : Simple

a = int(input())
b = int(input())
c = int(input())
d = int(input())
result = a + b + c + d
x = result // 60
y = result % 60
print(x)
print(y)