# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 6.
# time : 오후 6:50
# problem : https://www.acmicpc.net/problem/2355
# problem type : Math

x, y = map(int, input().split())
x, y = min(x, y), max(x, y)
print((x+y) * (y-x+1) // 2)