# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 19.
# time : 오후 6:19
# problem : https://www.acmicpc.net/problem/3009
# problem type : Math, Simple

# 한번 나오는 점의 좌표를 찍어주면 되는 쉬운 문제

x_dict = {}
y_dict = {}
for i in range(3):
    x, y = map(int, input().split())
    if x in x_dict: x_dict[x] = 2
    else: x_dict[x] = 1

    if y in y_dict: y_dict[y] = 2
    else: y_dict[y] = 1

res = []

for x in x_dict:
    if x_dict[x] == 1:
        res.append(x)

for y in y_dict:
    if y_dict[y] == 1:
        res.append(y)

print(' '.join(map(str, res)))