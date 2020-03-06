# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 6.
# time : 오후 9:44
# problem : https://www.acmicpc.net/problem/1339
# problem type : Math

# 백트래킹으로도 풀 수 있는 문제였지만 수학적으로 계산해서 풀었다
# 알파벳마다 자릿값들의 합을 구해 자릿값 합이 큰 순서대로 정렬해 9부터 순서대로 곱해주면 답
n = int(input())
d = dict()
for i in range(n):
    s = input()
    for j in range(len(s)): # 자릿값 할당
        if s[j] in d:
            d[s[j]] += 10 ** (len(s) - j - 1)
        else:
            d[s[j]] = 10 ** (len(s) - j - 1)
arr = []
for key in d:
    arr.append(d[key])

arr.sort(reverse=True) # 자릿값 배열 정렬

# 9부터 순서대로 자릿값과 곱해줌
x = 9
result = 0
for element in arr:
    result += x * element
    x -= 1

print(result)