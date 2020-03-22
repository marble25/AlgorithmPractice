# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 7.
# time : 오후 12:03
# problem : https://www.acmicpc.net/problem/1700
# problem type : Greedy

# Greedy한 기법이라는 것을 배울 수 있었음
n, k = map(int, input().split())
arr = list(map(int, input().split()))
plug = [0] * n

count = 0
for i in range(k):
    plugged_in = False

    # 이미 기기가 꽂혀 있는 상황
    for j in range(n):
        if plug[j] == arr[i]:
            plugged_in = True
            break

    if plugged_in:
        continue

    # 플러그가 비어있는 상황
    for j in range(n):
        if plug[j] == 0:
            plug[j] = arr[i]
            plugged_in = True
            break

    if plugged_in:
        continue

    # 가장 마지막에 사용하거나 안쓰는 기기 찾기
    max_index = -1
    plug_index = 0
    for j in range(n):
        index = 0 # 현재 플러그인 되어있는 장치가 가장 처음으로 쓰이는 지점
        for l in range(i+1, k):
            if plug[j] == arr[l]: # 이후에 쓰이는 지점
                break
            index += 1
        if index > max_index: # 가장 마지막에 쓰이는 기기 찾기
            plug_index = j
            max_index = index

    plug[plug_index] = arr[i]
    count += 1

print(count)