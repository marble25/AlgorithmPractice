# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 6.
# time : 오후 6:33
# problem : https://www.acmicpc.net/problem/9506
# problem type : Math

import math
from collections import deque

while True:
    n = int(input())
    if n == -1:
        break

    sum = 0
    arr = list()
    for i in range(1, int(math.sqrt(n))+1): # root n까지만 돌려도 약수를 찾아낼 수 있음
        if n % i != 0:
            continue
        arr.append(i) # i가 약수이면 n // i도 약수
        arr.append(n // i)

        sum += i
        sum += n // i

    arr.sort() # arr를 오름차순 순서로 정렬

    # 완전수가 아니면 출력
    if sum != n * 2:
        print('{} is NOT perfect.'.format(n))
        continue

    str = '{} = '.format(n)
    for i in range(len(arr)-1):
        if i == len(arr) - 2:
            str += '{}'.format(arr[i])
        else:
            str += '{} + '.format(arr[i])

    print(str)
