# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 18.
# time : 오후 9:55
# problem : https://www.acmicpc.net/problem/1672
# problem type : DP

# 왜 분류가 DP인지 모르겠는 문제
# 오른쪽부터 차례대로 table에 있는 문자열이랑 치환시켜주면 된다.

import sys

table = {
    'AA':'A', 'AG':'C', 'AC':'A', 'AT':'G',
    'GA':'C', 'GG':'G', 'GC':'T', 'GT':'A',
    'CA':'A', 'CG':'T', 'CC':'C', 'CT':'G',
    'TA':'G', 'TG':'A', 'TC':'G', 'TT':'T'
}
n = int(sys.stdin.readline())
s = sys.stdin.readline().strip()

for i in range(n-2, -1, -1):
    last_string = s[i:i+2]
    s = s.rsplit(last_string, 1)[0] + table[last_string]

print(s)