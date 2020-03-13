# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 13.
# time : 오후 7:16
# problem : https://www.acmicpc.net/problem/1722
# problem type : Math

# n!를 배열에 미리 저장해 놓고 순열 구할 때 더해주는 방식으로 풀었다.

dp = [1] * 25
for i in range(2, 21):
    dp[i] = dp[i-1] * i

visited = [False] * 21

n = int(input())
input_line = list(map(int, input().split()))
if input_line[0] == 1:
    k = input_line[1] - 1
    result = []
    for i in range(n-1, 0, -1):
        for j in range(1, n + 1):
            if visited[j] == True: continue # 이미 사용한 숫자는 pass
            if k >= dp[i]: # dp[i]보다 작아질 때까지 k 감소
                k -= dp[i]
                continue
            visited[j] = True # k가 dp[i]보다 작아졌을 때 result에 추가
            result.append(j)
            break

    for i in range(1, n+1): # result에 추가되지 않고 남아있는 것들 순서대로 추가
        if not visited[i]:
            result.append(i)
    print(' '.join(map(str, result)))
else:
    result = 1
    for i in range(n-1, 0, -1):
        arr_idx = n - i
        for j in range(1, n+1):
            if visited[j] == True: continue # 이미 사용된 숫자이면 pass
            if j == input_line[arr_idx]: # 해당하는 숫자가 나오면 탐색을 멈춤
                visited[j] = True
                break
            result += dp[i] # dp값 계속 더해줌

    print(result)