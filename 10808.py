# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 9.
# time : 오후 10:32
# problem : https://www.acmicpc.net/problem/10808
# problem type : String

s = input()
d = [0] * 26
for x in s:
    d[ord(x) - ord('a')] += 1

print(' '.join(map(str, d)))