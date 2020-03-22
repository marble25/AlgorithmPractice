# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 14.
# time : 오후 8:37
# problem : https://www.acmicpc.net/problem/1068
# problem type : Tree

def delete_node(node):
    global tree
    for next_node in tree[node][1]: # 자식 노드를 모두 탐색
        delete_node(next_node)

    tree[node] = [987654321, []] # 자신의 노드를 없앤다.

n = int(input())
input_line = list(map(int, input().split()))
tree = [[0, []] for _ in range(n)]
for i in range(n):
    parent = input_line[i]
    tree[i][0] = parent # tree의 0번째 index는 부모

    if parent == -1: continue # 부모 노드가 없을 경우 continue
    tree[parent][1].append(i)  # tree의 1번째 index는 자식 list, 부모의 자식 리스트에 i를 추가한다.

node = int(input())
parent = tree[node][0]
delete_node(node)
if parent != -1: # 부모가 있을 때는 부모의 자식 리스트에서 삭제
    tree[parent][1].remove(node)

cnt = 0
for i in range(n):
    if tree[i][0] != 987654321 and len(tree[i][1]) == 0: # 삭제된 노드가 아니고 자식이 없을 때(leaf 노드가 아닐 때)
        cnt += 1
print(cnt)