# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 11.
# time : 오후 5:01
# problem : https://www.acmicpc.net/problem/3649
# problem type : Binary Search

# 어렵지 않게 맞을 수 있었던 문제

import sys

while True:
    input_line = sys.stdin.readline()
    if not input_line:
        break

    x = int(input_line) * 10000000 # cm를 나노미터 단위로 바꿔준다.

    n = int(sys.stdin.readline())
    arr = []
    for i in range(n):
        arr.append(int(sys.stdin.readline()))

    arr.sort()

    low, high = 0, n - 1
    l1, l2 = 0, -1
    while low < high:
        if arr[high] + arr[low] == x: # 구멍 크기와 같으면
            if l2 - l1 < arr[high] - arr[low]: # 두 조각의 사이즈 차이를 최소로 함
                l1 = arr[low]
                l2 = arr[high]

            if low+1 < high and arr[low] == arr[low+1]: # low의 지금 조각과 다음 조각이 같으면 low 증가
                low += 1
            elif high-1 > low and arr[high] == arr[high-1]: # high의 지금 조각과 다음 조각이 같으면 high 감소
                high -= 1
            else: # 둘다 아니면 같아질 확률이 없기 때문에(하나는 그대로고 하나는 증가 혹은 감소하는데, 값이 똑같을 수 없다.)
                low += 1
                high -= 1

        elif arr[high] + arr[low] < x:
            low += 1

        else:
            high -= 1

    if l1 == 0 and l2 == -1: # l1, l2가 안바뀌었으면 채워넣을 수 없음
        print('danger')

    else:
        print('yes {} {}'.format(l1, l2))
