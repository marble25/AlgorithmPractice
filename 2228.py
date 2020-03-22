# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 29.
# time : 오후 5:03
# problem : https://www.acmicpc.net/problem/2228
# problem type : DP

# 종이에 점화식 써가면서 풀었던 문제
import sys

sys.setrecursionlimit(1000000)

n, m = map(int, sys.stdin.readline().split())
arr = []
for i in range(n):
    arr.append(int(sys.stdin.readline()))

# 음수들의 합이 결과로 나올 수 있기 때문에 적당히 작은 음수값으로 초기화
dp = [[[-987654321] * 2 for _ in range(n+1)] for __ in range(m+2)]

# dp[i][j][k] : i개의 그룹으로 이루어져 있고, j개의 수를 사용해서 선택 하거나 안했을 때(k=0 or 1), 구간 수의 합
def f(group_count, index, select):
    global n, m, arr, dp

    if index >= n: return -987654321 # 범위를 초과하는 값은 허용하지 않음
    if index == n-1 and group_count == m: return select * arr[index] # 마지막 index까지 도달했고 구간 갯수도 m개라면 현재 위치의 값을 보내줌(선택했으면 그 값, 선택 안했으면 0)
    if group_count > m: return -987654321 # 구간 갯수가 m을 넘어가는 것을 허용하지 않음
    if dp[group_count][index][select] != -987654321: return dp[group_count][index][select] # 기존에 값이 있으면 리턴
    if select == 0:
        maintain_group_without_select = f(group_count, index + 1, 0) # 다음 값도 선택 안함 -> 구간 갯수는 그대로
        add_group_with_select = f(group_count + 1, index + 1, 1) # 다음 값을 선택함 -> 구간 갯수를 1개 늘림
        dp[group_count][index][select] = max(maintain_group_without_select, add_group_with_select) # max값을 저장
    else:
        maintain_group_without_select = f(group_count, index + 1, 0) + arr[index] # 다음 값을 선택 안하는 경우 -> 구간 갯수 그대로
        maintain_group_with_select = f(group_count, index + 1, 1) + arr[index] # 새로운 구간을 만들지 않고 현재 구간에 더해주는 경우
        add_group_with_select = f(group_count+1, index + 2, 1) + arr[index] # 새로운 구간을 만드는 경우 -> 구간 사이에 공간을 넣어줌
        dp[group_count][index][select] = max(maintain_group_without_select, maintain_group_with_select, add_group_with_select) # max값 저장
    return dp[group_count][index][select]

print(max(f(0, 0, 0), f(1, 0, 1))) # 0번 인덱스를 선택하거나 선택하지 않거나