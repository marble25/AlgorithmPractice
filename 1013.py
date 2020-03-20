# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 20.
# time : 오후 11:29
# problem : https://www.acmicpc.net/problem/1013
# problem type : Simple

# 조건이 너무 많은 문제...
# 틀린 조건 찾기가 너무 까다로웠던 문제 ...

def check():
    global line
    if line[0] == '1':
        if len(line) < 3: return False # 길이가 3보다 작으면 100을 할 수 없으므로 False
        if line[0] != '1' or line[1] != '0' or line[2] != '0': return False # 100으로 시작하지 않으면 False

        # 1이 나올 때까지의 0을 빼버림
        i = 3
        while i < len(line):
            if line[i] == '1':
                break
            i += 1577
        if i == len(line) - 1 and line[i] == '1': # line의 마지막 글자가 1이면 True
            line = ''
            return True
        if i == len(line): return False # 끝까지 1이 없으면 False

        start_position = i
        # 0이 나올 때까지 1을 빼버림
        while i < len(line):
            if line[i] == '0':
                break
            i += 1

        if i == len(line): # 끝까지 0이 없으면 True
            line = ''
            return True
        elif i+1 < len(line) and line[i] == '0' and line[i+1] == '1': # 01이 나오면 line을 01 후로 돌림
            line = line[i+2:]
            return True
        elif i+1 < len(line) and i != start_position+1 and line[i] == '0' and line[i+1] == '0': # 00이 연속해서 나오면 line을 100 전으로 돌림
            line = line[i-1:]
            return True
        else: # 모두 아니면 False
            return False

    elif line[0] == '0':
        if len(line) < 2: return False # 길이가 2보다 작으면 01을 체크할 수 없으므로 False
        if line[1] == '1': # 01이 나오면 line을 01 후로 돌림
            line = line[2:]
            return True
        return False

import sys
T = int(sys.stdin.readline())
for _ in range(T):
    line = sys.stdin.readline().strip()
    while len(line) > 0:
        result = check()
        if not result:
            print('NO')
            break
    if len(line) == 0:
        print('YES')