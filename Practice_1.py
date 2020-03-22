# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 11.
# time : 오전 11:18

import math

n, m = map(int, input().split())
arr = list(map(int, input().split()))
one_index = 0
for i in range(n):
    if arr[i] == 1:
        one_index = i
        break

ans = 987654321
for i in range(m):
    if one_index - i < 0: continue
    if n-1 - (m-1-i) - one_index < 0: continue

    ans = min(ans, 1 + math.ceil((one_index - i) / (m-1)) + math.ceil(((n-1) - (m-1-i) - one_index) / (m-1)))

print(ans)