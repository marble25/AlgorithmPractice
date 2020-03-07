# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 7.
# time : 오후 10:43
# problem : https://www.acmicpc.net/problem/1543
# problem type : Greedy

s1 = input().strip()
s2 = input().strip()

result = 0
i = 0
while i < len(s1):
    # 단어를 포함하고 있는지 체크
    is_included = True
    for j in range(len(s2)):
        if i+j >= len(s1) or s1[i+j] != s2[j]:
            is_included = False
            break

    # 단어가 포함되어 있다면 단어 다음부터 다시 검사
    if is_included:
        i += len(s2)
        result += 1
    else:
        i += 1
print(result)