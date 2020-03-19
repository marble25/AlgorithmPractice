# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 19.
# time : 오후 6:23
# problem : https://www.acmicpc.net/problem/1436
# problem type : Brute Force

# 모든 종말의 수를 찾아가면서 하려고 했더니 너무 복잡했다.
# 그냥 단순히 i 증가하면서 종말의 수인지 체크하는 알고리즘으로도 가능했다.

n = int(input())
x = 666
while n > 0:
    temp = x
    flag = False
    while temp > 0:
        if temp % 1000 == 666: # 연속된 666이 있으면 break
            flag = True
            break
        temp //= 10

    if flag:
        n -= 1
    x += 1

print(x-1)