# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 7.
# time : 오후 8:26
# problem : https://www.acmicpc.net/problem/4153
# problem type : simple

while True:
    a, b, c = map(int, input().split())
    if a == b == c == 0:
        break

    max_val = max(a, b, c)
    min_val = min(a, b, c)
    mid_val = a+b+c - max_val - min_val

    if max_val ** 2 == min_val ** 2 + mid_val ** 2:
        print('right')
    else:
        print('wrong')