# project : baekjoon python algorithm practice
# user : marble
# date : 20. 2. 24.
# time : 오후 2:30

#######################
#
# Baekjoon Submit Information
#
#######################

# Runtime Error가 발생하는 경우
# 1. 배열에 할당된 크기를 넘어서 접근했을 때
# 2. 전역 배열의 크기가 메모리 제한을 초과할 때
# 3. 지역 배열의 크기가 스택 크기 제한을 넘어갈 때
# 4. 0으로 나눌 떄
# 5. 라이브러리에서 예외를 발생시켰을 때
# 6. 재귀 호출이 너무 깊어질 때
# 7. 이미 해제된 메모리를 또 참조할 때


# 입력할 때
# sys.stdin.readline()

# 재귀함수 사용할 때 추가할 부분
#
# import sys
#
# sys.setrecursionlimit(10000)

# 제출할 때 : PyPy3로 제출

# Queue를 사용할 때 : collections.deque 사용하자

# 우선순위 Queue 사용할 때: heapq 사용하자

# pypy를 사용할 때 : exit(0)이 아닌 sys.exit(0)을 사용!!!!

# pypy를 사용할 때 : 재귀를 지나치게 많이 사용했다면 런타임 에러가 뜨기도 함(추측인데 맞는 것 같음)