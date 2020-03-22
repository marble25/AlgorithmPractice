# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 21.
# time : 오전 11:07
# problem : https://www.acmicpc.net/problem/1234
# problem type : DP

# 깔끔하게 풀어낸 문제
# 역시 bottom-up으로 푸니 시간초과 문제도 해결되는 듯 하다

def calc_pascal(): # nCm을 저장해놓는 함수
    global pascal
    pascal[0][0] = 1
    for i in range(1, 12):
        pascal[i][0] = 1
        for j in range(1, 12):
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]



def solve(n, red, green, blue):

    # dp[stage][red][green][blue] : stage에 각각 red, green, blue만큼 남았을 때 선택하는 경우의 수
    dp = [[[[0] * (blue+1) for _ in range(green+1)] for __ in range(red+1)] for ___ in range(n+1)]

    dp[0][red][green][blue] = 1 # 초기 상태 설정
    for i in range(0, n):
        for r in range(0, red+1):
            for g in range(0, green+1):
                for b in range(0, blue+1):
                    if r >= i+1: dp[i+1][r-(i+1)][g][b] += dp[i][r][g][b] # 한 장난감만 선택
                    if g >= i+1: dp[i+1][r][g-(i+1)][b] += dp[i][r][g][b] # 한 장난감만 선택
                    if b >= i+1: dp[i+1][r][g][b-(i+1)] += dp[i][r][g][b] # 한 장난감만 선택
                    if (i+1) % 2 == 0: # i+1개 중 i+1 // 2개를 어떤 색으로, i+1 // 2를 다른 색으로 하고 배열하는 것이므로 현재 값에 배열하는 경우의 수 (i+1) C (i+1)//2를 곱해줌
                        if r >= (i+1) // 2 and g >= (i+1) // 2: dp[i+1][r-(i+1)//2][g-(i+1)//2][b] += dp[i][r][g][b] * pascal[i+1][(i+1) // 2]
                        if g >= (i+1) // 2 and b >= (i+1) // 2: dp[i+1][r][g-(i+1)//2][b-(i+1)//2] += dp[i][r][g][b] * pascal[i+1][(i+1) // 2]
                        if r >= (i+1) // 2 and b >= (i+1) // 2: dp[i+1][r-(i+1)//2][g][b-(i+1)//2] += dp[i][r][g][b] * pascal[i+1][(i+1) // 2]
                    if (i+1) % 3 == 0: # i+1개 중 i+1 // 3개를 r, i+1 // 3을 g, i+1 // 3을 b로 하고 배열하는 것이므로 현재 값에 (i+1) C (i+1)//3, (i+1)*2//2 C (i+1)//3을 곱해줌
                        if r >= (i+1) // 3 and g >= (i+1) // 3 and b >= (i+1) // 3: dp[i+1][r-(i+1)//3][g-(i+1)//3][b-(i+1)//3] += dp[i][r][g][b] * pascal[i+1][(i+1) // 3] * pascal[(i+1) * 2 // 3][(i+1) // 3]
    # 경우의 수 총합 리턴
    ret = 0
    for r in range(0, red+1):
        for g in range(0, green+1):
            for b in range(0, blue+1):
                ret += dp[n][r][g][b]
    return ret
n, red, green, blue = map(int, input().split())
pascal = [[0] * 12 for _ in range(12)]
calc_pascal()
ret = solve(n, red, green, blue)
print(ret)