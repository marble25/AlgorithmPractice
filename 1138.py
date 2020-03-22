# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 6.
# time : 오후 10:18
# problem : https://www.acmicpc.net/problem/1138
# problem type : Math

# 1번부터 차례대로 채워넣으면서 arr[i] 갯수만큼 빈칸을 센다
# 빈칸을 다 센 위치가 자신의 자리이다

n = int(input())
arr = []
result_arr = [0] * (n+1)
arr = list(map(int, input().split()))

for i in range(n):
    count = arr[i]
    for j in range(0, n):
        if result_arr[j] == 0:
            if count == 0:
                result_arr[j] = i + 1
                break
            count -= 1

for i in range(n):
    print(result_arr[i], end=' ')