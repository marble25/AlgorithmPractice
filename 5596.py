# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 13.
# time : 오후 3:26
# problem : https://www.acmicpc.net/problem/5596
# problem type : Simple

a, b, c, d = map(int, input().split())
result1 = a+b+c+d
a, b, c, d = map(int, input().split())
result2 = a+b+c+d
print(max(result1, result2))