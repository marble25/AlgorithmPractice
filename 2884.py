# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 7.
# time : 오후 8:21
# problem : https://www.acmicpc.net/problem/2884
# problem type : simple

h, m = map(int, input().split())
alarm_time = h * 60 + m
faster_time = alarm_time - 45 + 60*24
faster_h, faster_m = faster_time // 60 % 24, faster_time % 60
print(faster_h, faster_m)