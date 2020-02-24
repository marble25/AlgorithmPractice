# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 24.
# time : 오전 11:12
# problem : https://www.acmicpc.net/problem/10385
# problem type : DP

import sys

sys.setrecursionlimit(10000)

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
b = list(map(int, sys.stdin.readline().split()))

# ans[i][j]는 left top이 i이고, right top이 j일 때 최대 점수
ans = [[-1] * (n + 1) for _ in range(n + 1)]

def f(left_top, right_top):
    # 끝에 도달했다면 0 반환
    if left_top == n or right_top == n:
        return 0

    # 이미 값이 있다면 저장된 값 반환
    if ans[left_top][right_top] != -1:
        return ans[left_top][right_top]

    # 왼쪽 카드를 뺐을 때와 둘 다 뺐을 때 중 더 점수가 큰 값을 저장
    ans[left_top][right_top] = max(f(left_top + 1, right_top), f(left_top + 1, right_top + 1))

    # 오른쪽 카드 점수와 오른쪽 카드를 뺐을 경우의 합
    if a[left_top] > b[right_top]:
        ans[left_top][right_top] = max(ans[left_top][right_top], f(left_top, right_top + 1) + b[right_top])

    return ans[left_top][right_top]

print(f(0, 0))