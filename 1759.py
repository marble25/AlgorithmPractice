# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 17.
# time : 오후 12:32
# problem : https://www.acmicpc.net/problem/1759
# problem type : Backtracking

# 백트래킹을 사용한 간단한 문제

def dfs(index, stage, arr, visited, vo):
    if stage == l:
        if vo < 1 or l - vo < 2: return # 자, 모음 조건 안맞으면 넘어감
        print(''.join(visited))
        return

    for i in range(index, c): # 현위치부터 끝까지 중
        visited[stage] = arr[i] # 경로를 추가
        vowel_count = vo + 1 if arr[i] in vowel else vo # arr[i]가 모음이면 모음 갯수 + 1
        dfs(i+1, stage+1, arr, visited, vowel_count)
        visited[stage] = ''

import sys
sys.setrecursionlimit(10 ** 7)
l, c = map(int, sys.stdin.readline().split())

arr = list(map(str, sys.stdin.readline().split()))
arr.sort() # 사전순 출력을 위한 정렬

vowel = {'a':1, 'e':1, 'i':1, 'o':1, 'u':1} # 모음 저장

dfs(0, 0, arr, [''] * (l+1), 0)