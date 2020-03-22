# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 15.
# time : 오후 3:41
# problem : https://www.acmicpc.net/problem/2162
# problem type : Geometry, Graph Theory

# CCW라는 새로운 기하 알고리즘을 알 수 있었음
# 선분 교차 알고리즘도 알 수 있었음

def is_bigger(x1, y1, x2, y2):
    return x1 ** 2 + y1 ** 2 < x2 ** 2 + y2 ** 2

def ccw(x1, y1, x2, y2, x3, y3):
    result = x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1
    if result > 0: return 1 # 반시계방향이면 1 리턴
    elif result < 0: return -1 # 시계방향이면 -1 리턴
    else: return 0 # 일직선이면 0 리턴

def segment_intersects(x1, y1, x2, y2, x3, y3, x4, y4):
    p12 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4)
    p34 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2)

    if p12 == 0 and p34 == 0: # 두 선분이 한 직선에 있거나 끝점이 겹치는 경우
        if not is_bigger(x1, y1, x2, y2): (x1, y1), (x2, y2) = (x2, y2), (x1, y1) # x1, y1을 더 작은값, x2, y2를 더 큰 값으로 설정해놓는다.
        if not is_bigger(x3, y3, x4, y4): (x3, y3), (x4, y4) = (x4, y4), (x3, y3) # x3, y3를 더 작은값, x4, y4를 더 큰 값으로 설정해 놓는다.

        return not (is_bigger(x4, y4, x1, y1) or is_bigger(x2, y2, x3, y3)) # x3, y3이 x1, y1보다 모두 작거나 x1, x2가 x3, y3보다 모두 작으면(한 선분이 일직선 상이면서 겹치지 않는 경우) False 리턴, 아니면 True
    return p12 <= 0 and p34 <= 0

import sys
n = int(sys.stdin.readline())
groups = {}
for i in range(n):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    candidates = []
    for group in groups:
        for seg in groups[group]:
            if segment_intersects(seg[0], seg[1], seg[2], seg[3], x1, y1, x2, y2): # 선분 교차하면 후보에 group index 넣음
                candidates.append(group)
                break

    if len(candidates) == 0: # 후보가 없으면 새로 그룹 만듦
        groups[i] = [(x1, y1, x2, y2)]
    elif len(candidates) == 1: # 후보가 하나면 거기다 넣음
        groups[candidates[0]].append((x1, y1, x2, y2))
    else: # 후보가 둘 이상이면
        for group in candidates[1:]:
            groups[candidates[0]].extend(groups[group]) # 후보0으로 다른 그룹들 모두 합침
            del groups[group]
        groups[candidates[0]].append((x1, y1, x2, y2)) # 후보0에 넣음

max_val = -1
for group in groups:
    max_val = max(max_val, len(groups[group]))
print(len(groups))
print(max_val)