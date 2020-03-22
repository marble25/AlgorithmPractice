# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 21.
# time : 오후 6:41
# problem : https://www.acmicpc.net/problem/1081
# problem type : DP

# 어렵지 않은 문제였지만 조건이 너무 까다로웠던 문제
# 이런 문제도 잘 풀 수 있어야 한다.

import math

def calc_num(num):
    if num <= 0: return 0
    log_num = int(math.log10(num))
    y = 0
    while num > 0:
        high_val = num // (10 ** log_num)  # 제일 높은 자릿수
        y += high_val * (high_val - 1) * (10 ** log_num) // 2  # 0~제일 높은 자릿수까지
        y += high_val * (num % (10 ** log_num) + 1)  # 제일 높은 자릿수 갯수
        y += 45 * log_num * high_val * (10 ** (log_num - 1))  # 다른 애들 자릿수 갯수
        num %= (10 ** log_num)
        log_num -= 1

    return int(y)

l, u = map(int, input().split())
print(calc_num(u) - calc_num(l-1))