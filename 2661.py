# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 17.
# time : 오후 2:59
# problem : https://www.acmicpc.net/problem/2661
# problem type : Backtracking

# 조건만 잘 생각해주면 쉽게 풀 수 있는 문제

def dfs(stage, path):
    if stage == n+1: # 길이가 n일 때까지 왔으면 출력
        print(''.join(map(str, path[1:])))
        sys.exit(0)
    visited = [False] * 4
    for i in range(1, stage // 2 + 1): # i*2칸 전에서 시작된 수열과 i칸 전에서 시작된 수열이 같다면 현재 값을 i*2칸에서 시작된 수열의 끝값이면 안된다.
        flag = True
        for j in range(1, i):
            if path[stage-i*2+j] != path[stage-i+j]: # 수열이 동일하지 않으므로 생각할 필요 없음
                flag = False
                break

        if flag:
            visited[path[stage-i]] = True

    for i in range(1, 4):
        if not visited[i]: # 안되는 숫자가 아니라면 탐색
            path[stage] = i
            dfs(stage+1, path)
            path[stage] = 0


import sys
sys.setrecursionlimit(10 ** 7)
n = int(sys.stdin.readline())
path = [0] * (n+1)
dfs(1, path)