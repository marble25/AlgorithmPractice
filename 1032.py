# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 9.
# time : 오후 10:42
# problem : https://www.acmicpc.net/problem/1032
# problem type : String

import sys
N = int(sys.stdin.readline())
arr = []
for i in range(N):
    arr.append(sys.stdin.readline().strip())

str_size = len(arr[0])
result_str = ''
for i in range(str_size):
    default_str = arr[0][i] # 기준점을 0번 index의 str으로 정함
    for j in range(1, N):
        if arr[j][i] != default_str: # 다른 것이 하나라도 있으면 물음표로 표현
            result_str += '?'
            break

    if len(result_str) == i: # break문을 거치지 않았으면(다른 것이 하나도 없으면) default_str을 더해줌
        result_str += default_str

print(result_str)