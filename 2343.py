# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 10.
# time : 오후 9:20
# problem : https://www.acmicpc.net/problem/2343
# problem type : Binary Search

# M개 이하로 넣어도 되는지 헷갈려서 틀렸던 문제

import sys

n, m = map(int, sys.stdin.readline().split())
arr = [0] + list(map(int, sys.stdin.readline().split()))

# 부분합을 미리 구해놓는다.
# partial_sum[i] : 1~i까지의 arr의 합
partial_sum = [0] * (n+1)
partial_sum[1] = arr[1]
for i in range(2, n+1):
    partial_sum[i] = partial_sum[i-1] + arr[i]

# 어떤 수 mid를 블루레이 크기로 생각했을 때 m개 이하로 만들 수 있는지 판단, 만들 수 있으면 답과 비교해서 최솟값으로 업데이트
low = 1
high = 1000000000
ans = 1000000005
while low <= high:
    mid = (low + high) // 2

    prev_index = 0
    cnt = 0
    flag = False
    i = 1
    while i <= n:
        if partial_sum[i] - partial_sum[prev_index] > mid:
            if i == prev_index + 1: # 1개짜리임에도 블루레이에 안들어가면 완전히 실패한 것이므로 break
                flag = True
                break
            prev_index = i - 1
            cnt += 1
        else:
            i += 1

    cnt += 1 # 마지막 블루레이는 안셌으므로 하나 더해줌
    if flag:
        low = mid + 1
    elif cnt <= m:
        ans = min(mid, ans)
        high = mid - 1
    elif cnt > m:
        low = mid + 1

print(ans)