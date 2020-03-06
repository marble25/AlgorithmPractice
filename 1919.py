# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 6.
# time : 오후 9:26
# problem : https://www.acmicpc.net/problem/1919
# problem type : Math

s1 = input()
s2 = input()

dict = dict()

for spell in s1: # s1 알파벳의 갯수를 카운팅하는 dict를 만듦
    if spell in dict:
        dict[spell] += 1
    else:
        dict[spell] = 1

# s1과 s2 간에 겹치는 알파벳 갯수를 count
count = 0
for spell in s2:
    if spell in dict:
        if dict[spell] > 0:
            dict[spell] -= 1
            count += 1

print(len(s1) + len(s2) - count * 2) # 겹치는 것을 제외하여 제거할 문자수 구함