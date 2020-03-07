# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 7.
# time : 오후 12:48
# problem : https://www.acmicpc.net/problem/1969
# problem type : Greedy

# 현재 위치에서 가장 많이 쓰이는 문자를 찾아서 Result DNA의 그 위치를 해당 문자로 설정하면 끝

import sys
n, m = map(int, sys.stdin.readline().split())
s = []
for i in range(n):
    s.append(sys.stdin.readline().strip())

s.sort()

result_str = ''
result_distance = 0

for i in range(m):
    # i 위치의 문자 카운팅
    d = [0] * 26
    for j in range(n):
        d[ord(s[j][i]) - ord('A')] += 1

    # 가장 많이 쓰이는 문자를 가져옴
    m_index = 0
    m_val = -1
    for j in range(0, 26):
        if m_val < d[j]:
            m_index = j
            m_val = d[j]

    # i번째의 DNA string과 distance를 구성
    result_str += chr(ord('A') + m_index)
    result_distance += (n - m_val)

print(result_str)
print(result_distance)