# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 13.
# time : 오후 12:37
# problem : https://www.acmicpc.net/problem/5597
# problem type : Simple

d = dict()
for i in range(28):
    d[int(input())] = 1

for i in range(1, 31):
    if i not in d:
        print(i)