# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 12.
# time : 오후 9:39
# problem : https://www.acmicpc.net/problem/1344
# problem type : DP

# DP 안쓰고 수학으로 풀려다가 빙 돌아간 문제

# prob[0] : A가 넣을 퍼센트
# prob[1] : B가 넣을 퍼센트
prob = [0, 0]
prob[0] = int(input())
prob[1] = int(input())

cases = []
primes = {2: 1, 3: 1, 5: 1, 7: 1, 11: 1, 13: 1, 17: 1} # 소수들을 미리 넣어놓는다.
dp = [[[0] * 19 for _ in range(19)] for __ in range(19)]

# dp[i][j][k] : i번째 시간에 점수 현황이 j:k일 경우
dp[0][0][0] = 1
for stage in range(1, 19):
    for i in range(stage+1):
        for j in range(stage+1):
            # 순서대로
            # 1. A와 B 둘다 득점(둘다 골 넣을 확률 곱해줌)
            # 2. A만 득점(A는 넣을 확률, B는 못넣을 확률 곱해줌)
            # 3. B만 득점(A는 못 넣을 확률, B는 넣을 확률 곱해줌)
            # 4. A, B 둘다 무득점(둘다 골 못넣을 확률 곱해줌)
            dp[stage][i][j] = dp[stage-1][i-1][j-1] * prob[0] * prob[1] \
                              + dp[stage-1][i-1][j] * prob[0] * (100-prob[1]) \
                              + dp[stage-1][i][j-1] * prob[1] * (100-prob[0]) \
                              + dp[stage-1][i][j] * (100-prob[0]) * (100-prob[1])

result = 0
for i in range(19):
    for j in range(19):
        if i in primes or j in primes: # 점수 둘 중 하나라도 소수면 result에 더해줌
            result += dp[18][i][j]

result = result * ((0.01) ** 36) # 확률 구하기 위해 0.01의 36제곱(확률을 총 36번 곱해줬으므로)

print(result)