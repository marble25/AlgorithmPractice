# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 6.
# time : 오후 11:46
# problem : https://www.acmicpc.net/problem/2437
# problem type : Greedy

# 단순히 for문 2개로 풀려고 해서 시간 초과가 났던 문제

n = int(input())
arr = list(map(int, input().split()))

arr.sort()

sum = 0 # 지금까지의 모든 숫자의 합, 0~sum까지는 무게 측정 가능
for i in range(n):
    if arr[i] > sum + 1: # sum보다 2 이상 크면 sum+1을 측정할 수 없음
        break
    sum += arr[i]

print(sum + 1)