# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 10.
# time : 오후 2:47
# problem : https://www.acmicpc.net/problem/7453
# problem type : Binary Search

# 이진 탐색이 아직 너무 어렵다...

import sys
n = int(sys.stdin.readline())
A, B, C, D = [], [], [], []
for i in range(n):
    a, b, c, d = map(int, sys.stdin.readline().split())
    A.append(a)
    B.append(b)
    C.append(c)
    D.append(d)

# A, B, C, D를 X, Y집합 2개로 만듦
X = []
Y = []
for i in range(n):
    for j in range(n):
        X.append(A[i]+B[j])
        Y.append(C[i]+D[j])

X.sort()
Y.sort()

ans = 0
x = 0
y = n ** 2 - 1
while True:
    if x >= n ** 2 or y < 0: break # 범위 벗어나면 break
    result = X[x] + Y[y]
    if result > 0:
        y -= 1
    elif result < 0:
        x += 1

    if result == 0: # 0이 되는 값이면
        org_x, org_y = x, y
        cnt_x, cnt_y = 0, 0

        while x < n ** 2 and X[x] + Y[org_y] == 0: # X 배열에서 같은 값 세기
            x += 1
            cnt_x += 1

        while y >= 0 and X[org_x] + Y[y] == 0: # Y 배열에서 같은 값 세기
            y -= 1
            cnt_y += 1

        ans += cnt_x * cnt_y # X배열 같은 값 개수 * Y배열 같은 값 개수

print(ans)