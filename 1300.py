# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 9.
# time : 오후 11:55
# problem : https://www.acmicpc.net/problem/1300
# problem type : Binary Search

# 이분탐색이라고 무시하면 안되겠다는 다짐을 가지게 되었다.
# 이분탐색 너무 어려운 것...

import sys
sys.setrecursionlimit(100000)

n = int(input())
k = int(input())

low = 1
high = k # high이 n*n이 아닌 k여도 되는 이유 : N * N 배열에서 i=1인 경우만 고려해도 배열에 있는 K 이하인 수 갯수가 K개는 넘기 때문(1, 2, 3, 4, ... , K까지)

result = 0
while low <= high:
    mid = (low + high) // 2

    # B[cnt] = mid인 cnt를 구하기
    cnt = 0
    for i in range(1, n+1): # n+1까지 모든 행에 대해서
        cnt += min(mid // i, n) # i행에 있는 숫자들은 모두 i의 배수이다. i로 나누어 준다면 mid보다 작거나 같은 숫자의 갯수가 나온다.

    if cnt < k:
        low = mid + 1
    else:
        high = mid - 1
        result = mid

print(result)