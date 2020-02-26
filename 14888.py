# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 26.
# time : 오후 3:09
# problem : https://www.acmicpc.net/problem/14888
# problem type : Brute Force

import sys

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
ops = list(map(int, sys.stdin.readline().split()))
max_value = -1987654321
min_value = 1987654321

# stage : 현재 처리할 a값의 index
# value : 앞에서 연산한 값
# current_ops : 남은 연산자를 저장해놓은 배열
def f(stage, value, current_ops):
    global max_value, min_value

    # 배열의 끝이라면 max, min값 계산
    if stage == n:
        max_value = max(value, max_value)
        min_value = min(value, min_value)
        return

    # 남은 연산자를 배열에서 찾음
    for (index, operator_left) in enumerate(current_ops):
        if operator_left != 0: # 연산자가 1개 이상 남았다면
            # 다음 값을 연산자에 맞게 계산
            next_value = value

            if index == 0:
                next_value += a[stage]

            elif index == 1:
                next_value -= a[stage]

            elif index == 2:
                next_value *= a[stage]

            # c++ 스타일의 정수 나눗셈 처리
            elif index == 3:
                sign = 1 if next_value * a[stage] > 0 else -1
                next_value = abs(next_value) // abs(a[stage])
                next_value *= sign

            current_ops[index] -= 1 # 현재 사용한 연산자를 감소
            ret = f(stage + 1, next_value, current_ops) # 다음 스테이지로 넘어감
            current_ops[index] += 1 # 현재 사용한 연산자를 원상복구

f(1, a[0], ops) # a[0]을 기본으로 갖고 시작하기 때문에 stage는 1
print(max_value)
print(min_value)
