# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 6.
# time : 오후 11:10
# problem : https://www.acmicpc.net/problem/1783
# problem type : Greedy

# 간단한 문제였음에도 실수로 여러번 틀림
# 실수를 줄여야 함
n, m = map(int, input().split())

if n == 1: # n이 1이면 어떤 경우에도 더 나아갈 수 없다
    print('1')
elif n == 2: # n이 2이면 1칸 위로, 2칸 오른쪽 or 1칸 아래로, 2칸 오른쪽을 갈 수 있다.
    print(min(4, (m+1) // 2)) # 5는 나올 수 없음
elif m <= 3: # n이 3 이상이면서 m이 3보다 작거나 같으면 2칸 위로, 1칸 오른쪽 or 2칸 아래로, 1칸 오른쪽을 갈 수 있다.
    print(m)
elif m == 4: # m이 4이면 2칸 위로, 1칸 오른쪽 + 2칸 아래로, 1칸 오른쪽 + 2칸 위로, 1칸 오른쪽을 갈 수 있다.
    print(4)
elif m <= 7: # m이 7 이하면 2칸 위로, 1칸 오른쪽 or 2칸 아래로, 1칸 오른쪽을 갈 수 있다.
    print(3+(m-3) // 2) # 5는 넘을 수 없다.
else:
    m -= 6 # 모두 사용하면 오른쪽으로 6칸 가게 된다. + 횟수는 5이다.
    print(m + 4) # 횟수를 더해줌(1 시작이라서 1개 뺌)