# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 25.
# time : 오전 12:00
# problem : https://www.acmicpc.net/problem/2602
# problem type : DP

import sys
sys.setrecursionlimit(100000)

target_string = input()
devil_string = input()
angel_string = input()

# dp 배열 초기화
dp = []
for i in range(len(target_string) + 1):
    dp.append([])
    for j in range(len(devil_string) + 1):
        dp[i].append([-1, -1])

# 마법의 두루마리 적힌 문자열의 index, 돌다리 index, 이전에 골랐던 돌다리가 악마의 돌다리인지 천사의 돌다리인지
def f(target_stage, string_stage, is_devil):
    global target_string, devil_string, angel_string, dp

    if dp[target_stage][string_stage][is_devil] != -1: return dp[target_stage][string_stage][is_devil] # dp값이 있으면 dp 리턴
    if target_stage == len(target_string)-1: return 1 # target이 끝까지 왔다면 건널 수 있음
    if string_stage == len(devil_string)-1: return 0 # target이 끝까지 안왔는데 돌다리의 끝까지 왔다면 건널 수 없음

    compare_string = devil_string if is_devil == 0 else angel_string # 현재 골라야 하는 돌다리

    # 끝의 다리까지 돌면서 건널 수 있다면 f 호출
    dp[target_stage][string_stage][is_devil] = 0
    for i in range(string_stage+1, len(devil_string)):
        if target_string[target_stage+1] == compare_string[i]:
            dp[target_stage][string_stage][is_devil] += f(target_stage+1, i, 1-is_devil)

    return dp[target_stage][string_stage][is_devil]

print(f(-1, -1, 0) + f(-1, -1, 1))