# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 24.
# time : 오후 2:40
# problem : https://www.acmicpc.net/problem/1958
# problem type : DP, LCS

# 이 문제를 풀면서 주의할 점
# 단순히 2차원 LCS를 두번 돌리면 안됨
# 2차원 LCS를 돌린 결과는 가장 긴 것만 뽑아낼 수 있는데, 정답은 가장 긴 것이 아닌 중간 순위의 다른 문자열을 요구할 수 있기 때문

import sys

# 입력받은 문장의 길이를 늘려주기 위해서 앞에 0을 추가함
input1 = '0' + sys.stdin.readline().strip()
input2 = '0' + sys.stdin.readline().strip()
input3 = '0' + sys.stdin.readline().strip()

def lcs(s1, s2, s3):
    # dp[i][j][k] : s1[i]와 s2[j]와 s3[k]까지의 Common Subsequence중 가장 긴 것의 길이
    dp = [[[0] * 105 for _ in range(105)] for __ in range(105)]

    for i in range(1, len(s1)):
        for j in range(1, len(s2)):
            for k in range(1, len(s3)):
                if s1[i] == s2[j] and s2[j] == s3[k]: # s1[i]와 s2[j]와 s3[k]가 같으면 이전 결과에다 1을 더해줌
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1
                else: # 주위 결과 중 가장 큰 값을 저장
                    dp[i][j][k] = max(dp[i][j-1][k], dp[i-1][j][k], dp[i][j][k-1])

    # 가장 긴 길이를 찾아
    max_value = -1

    for i in range(len(s1)):
        for j in range(len(s2)):
            for k in range(len(s3)):
                if max_value < dp[i][j][k]:
                    max_value = dp[i][j][k]

    return max_value


print(lcs(input1, input2, input3))