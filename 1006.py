# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 12.
# time : 오후 1:05
# problem : https://www.acmicpc.net/problem/1006
# problem type : DP

# 굉장히 까다로운 문제
# 4시간 정도 고민해도 도저히 답이 안나와서(Test Case를 모두 만족시키는 경우가 없었다.) 풀이를 보았는데 풀이도 이해하기 어려웠다.
# 모르는 부분은 https://casterian.net/archives/1356 참고

import sys

def solve(index):
    global A, B, C
    for i in range(index, n): # 그림을 그려서 경우의 수를 모두 따지면 됨
        A[i+1] = min(B[i]+1, C[i]+1)
        if arr[i][0] + arr[i][1] <= w:
            A[i+1] = min(A[i+1], A[i]+1)
        if arr[i-1][0] + arr[i][0] <= w and arr[i-1][1] + arr[i][1] <= w:
            A[i+1] = min(A[i+1], A[i-1]+2)

        if i == n-1: continue
        B[i+1], C[i+1] = A[i+1]+1, A[i+1]+1
        if arr[i][0] + arr[i+1][0] <= w:
            B[i+1] = min(B[i+1], C[i]+1)
        if arr[i][1] + arr[i+1][1] <= w:
            C[i+1] = min(C[i+1], B[i]+1)

T = int(sys.stdin.readline())
for _ in range(T):
    n, w = map(int, sys.stdin.readline().split())
    arr = [[0] * 2 for _ in range(n+1)]
    for i in range(2):
        input_list = list(map(int, sys.stdin.readline().split()))
        for j in range(n):
            arr[j][i] = input_list[j]

    # A[i] : 0행과 1행 모두 i-1까지 채워져 있는 가짓수
    # B[i] : 0행은 i까지, 1행은 i-1까지 채워져 있는 가짓수
    # C[i] : 0행은 i-1까지 1행은 i까지 채워져 있는 가짓수
    A, B, C = [0] * 10005, [0] * 10005, [0] * 10005
    A[0] = 0 # 사용한 부대가 없으므로 0
    B[0] = C[0] = 1 # 각각 0행과 1행을 1개씩 채우므로 1
    solve(0)
    result = A[n] # 최종 값은 0행과 1행 모두 n-1까지 채워져 있는 A[n]이 답

    if n > 1 and arr[0][0] + arr[n-1][0] <= w: # 0행의 0번째와 n-1번째가 이어질 경우 0, 0을 빼고 생각
        A[1] = 1 # 0, 1 한 자리밖에 안남으므로 1
        B[1] = 2 # 0, 1과 1, 0 두자리 있으므로 2
        C[1] = 1 if arr[0][1] + arr[1][1] <= w else 2 # 0, 1과 1, 1이 이어질 수 있으면 1, 아니면 각각 해서 0
        solve(1)

        result = min(result, C[n-1]+1) # 결과에다 0, 0과 0, n-1 이어진 1 추가

    if n > 1 and arr[0][1] + arr[n-1][1] <= w: # 1행의 0번째와 n-1번째가 이어질 경우 0, 1을 빼고 생각
        A[1] = 1 # 0, 0 한 자리밖에 안남으므로 1
        B[1] = 1 if arr[0][0] + arr[1][0] <= w else 2 # 0, 0과 1, 0이 이어질 수 있으면 1, 아니면 각각 해서 0
        C[1] = 2 # 0, 0과 1, 1 두 자리 있으므로 2
        solve(1)

        result = min(result, B[n-1] + 1) # 결과에다 0, 1과 n-1, 1 이어진 1 추가

    if n > 1 and arr[0][1] + arr[n-1][1] <= w and arr[0][0] + arr[n-1][0] <= w: # 0행과 1행 모두 0번째와 n-1번째가 이어질 경우 0열을 아예 빼고 생각
        A[1] = 0 # 1부터 시작하는 것 빼고는 기본 조건과 동일
        B[1] = C[1] = 1
        solve(1)

        result = min(result, A[n-1] + 2) # 처음에 이어진 것이 2개이므로 2 추가

    print(result)