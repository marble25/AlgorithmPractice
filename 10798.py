# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 7.
# time : 오후 8:29
# problem : https://www.acmicpc.net/problem/10798
# problem type : simple

max_len = -1
s = []
for i in range(5):
    s.append(input().strip())
    max_len = max(max_len, len(s[i]))

result = ''
for i in range(max_len):
    for j in range(5):
        if len(s[j]) <= i:
            continue
        result += s[j][i]

print(result)
