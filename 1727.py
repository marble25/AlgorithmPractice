# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 18.
# time : 오전 11:31
# problem : https://www.acmicpc.net/problem/1727
# problem type : DP

# s1이 작고 s2가 크므로 s1의 모든 요소들은 다 사용되어야 한다.
def dfs(x, y):
    global dp
    if x == n: return 0 # s1이 모두 사용되었으므로 정답
    if y == m: return 987654321 # s1이 모두 사용되지 않았는데 s2가 다 사용되었으므로 오답
    if n-x > m-y: return 987654321 # s1 남은 부분이 s2 남은 부분보다 크면 s1을 다 쓸 수 없으므로 오답
    if dp[x][y] != 987654321: return dp[x][y]
    dp[x][y] = min(dfs(x, y+1), dfs(x+1, y+1) + abs(s1[x]-s2[y])) # x를 이용하지 않는 경우와 x를 이용하는 경우 중 최솟값을 리턴
    return dp[x][y]

import sys
sys.setrecursionlimit(10 ** 7)
n, m = map(int, sys.stdin.readline().split())
s1 = list(map(int, sys.stdin.readline().split()))
s2 = list(map(int, sys.stdin.readline().split()))

s1.sort()
s2.sort()

if n > m: # s2를 크기가 더 큰 집합으로 만들기 위해서 바꿔줌
    n, m = m, n
    s1, s2 = s2, s1

dp = [[987654321] * 1005 for _ in range(1005)]
print(dfs(0, 0))