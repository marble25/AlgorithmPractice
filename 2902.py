# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 9.
# time : 오후 10:37
# problem : https://www.acmicpc.net/problem/2902
# problem type : String

s = input()
arr = s.split('-')
result = ''
for el in arr:
    result += el[0]

print(result)