# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 13.
# time : 오후 6:38
# problem : https://www.acmicpc.net/problem/2921
# problem type : Math

# 겁나 돌아가게 풀었던 문제
# 간단하게 풀면 되는데...

n = int(input())
res = 0
for i in range(0, n+1):
    for j in range(i, n+1):
        res += i + j
print(res)