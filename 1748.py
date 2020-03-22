# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 13.
# time : 오후 12:41
# problem : https://www.acmicpc.net/problem/1748
# problem type : Simple

n = int(input())

t = 1
res = 0
while n >= 10 ** t:
    res += (10 ** (t-1)) * 9 * t
    t += 1

res += (n + 1 - (10 ** (t-1))) * t
print(res)