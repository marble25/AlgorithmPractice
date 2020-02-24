# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 23.
# time : 오후 11:17
# problem : https://www.acmicpc.net/problem/1256
# problem type : DP

# input 입력
n, m, k = map(int, input().split())

# nCm을 빨리 구하기 위해 이항계수를 저장
# pascal[i][j] : i개의 길이의 문자열 중에 z가 j개 있는 문자열의 갯수
pascal = [[0] * (n+m+1) for _ in range(n+m+1)]
pascal[0][0] = 1
for i in range(1, n+m+1):
    pascal[i][0] = 1
    for j in range(1, n+m+1):
        pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]

# while문을 돌기 위한 x, y, k, result 세팅
x, y = n+m, m
k -= 1
result = ''

# 사전에 수록되어 있는 문자열의 개수가 K보다 작으면 -1 출력
if k >= pascal[n+m][m]:
    print(-1)
    exit()

while k:
    if k >= pascal[x][y]: # xCy보다 크다 : 그 자리가 z에 해당
        result += 'z'
        k -= pascal[x][y]
        x -= 1 # 문자열을 하나 채웠으므로 문자열 길이 감소
        y -= 1 # z를 하나 썼으므로 z 갯수 감소
    else: # xCy보다 작다 : 그 자리가 a에 해당
        result += 'a'
        x -= 1 # 문자열을 하나 채웠으므로 문자열 길이 감소, z는 안썼으므로 z 갯수는 그대로

# a와 z가 채워지지 않은 나머지 문자열을 채움
result += 'a' * (x-y) # a의 갯수 : 문자열 길이에서 z 갯수 뺀 갯수
result += 'z' * (y) # z의 갯수 : y개

print(result)
