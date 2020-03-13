# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 13.
# time : 오후 12:39
# problem : https://www.acmicpc.net/problem/5063
# problem type : Simple

n = int(input())
for _ in range(n):
    r, e, c = map(int, input().split())
    if e-c > r:
        print('advertise')
    elif e-c < r:
        print('do not advertise')
    else:
        print('does not matter')