# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 5.
# time : 오후 1:47
# problem : https://www.acmicpc.net/problem/1695
# problem type : DP

# 이 소스코드는 파이썬으로 제출하지 못함
# 파이썬의 문제로 메모리 초과 및 시간 초과
# 동일한 소스코드를 C++로 제출, accepted
import sys
sys.setrecursionlimit(1000010)

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

dp = [[-1] * (5005) for _ in range(5005)]

def f(left, right):
    global dp

    if left >= right: return 0
    if dp[left][right] != -1: return dp[left][right]
    if arr[left] == arr[right]: # 왼쪽과 오른쪽이 동일하면 count 증가 없음
        dp[left][right] = f(left+1, right-1)
    else:
        dp[left][right] = min(f(left+1, right), f(left, right-1)) + 1 # 왼쪽으로 맞춘 것과 오른쪽으로 맞춘 것 중 최소값을 대입
    return dp[left][right]

print(f(0, n-1))