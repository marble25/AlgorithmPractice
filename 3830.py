# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 15.
# time : 오후 7:06
# problem : https://www.acmicpc.net/problem/3830
# problem type : Union-Find, Disjoint-Set

# 까다로운 문제였는데 Union-Find라는 알고리즘을 적용할 수 있다는 힌트를 받고 풀어본 문제
# 새로운 알고리즘을 알 수 있었던 문제

def find(u):
    global parent, diff
    if parent[u] == u: return u # 루트 노드이면 return
    current_parent = parent[u] # 현재 부모를 저장해 놓음
    parent[u] = find(parent[u]) # 부모 노드를 업데이트
    diff[u] += diff[current_parent] # 현재 부모의 값으로 업데이트
    return parent[u]

def union(u, v, w):
    global diff, rank, parent

    u_root = find(u)
    v_root = find(v)

    if u_root == v_root: return
    if rank[u_root] > rank[v_root]: # u의 깊이가 v의 깊이보다 크면 v를 u에 붙인다.
        parent[v_root] = u_root # v_root의 부모를 u_root로 함
        diff[v_root] += diff[u]-w-diff[v] # w는 v무게 - w무게이므로 v_root를 u_root로 바꾸었을 때 식을 유도해보면 v_root무게 + u_root무게-u무게-(v무게-u무게)-(v_root무게-v무게)이므로 u_root무게가 나온다.
    else: # 위와 반대로 해주면 된다.
        parent[u_root] = v_root
        diff[u_root] += diff[v]+w-diff[u]

    if rank[u_root] == rank[v_root]: # 깊이가 같을 때에는 u_root를 v_root 밑에 넣으므로 v_root의 깊이를 1 증가
        rank[v_root] += 1

import sys
sys.setrecursionlimit(1000000)

while True:
    n, m = map(int, sys.stdin.readline().split())
    if n == m == 0: break

    diff = [0 for i in range(n+1)] # 루트 노드에서 i 노드의 무게를 뺀 값
    parent = [i for i in range(n+1)]
    rank = [1 for _ in range(n+1)]

    for i in range(m):
        input_line = sys.stdin.readline().split()
        if input_line[0] == '!':
            a, b, w = map(int, input_line[1:])
            union(a, b, w)
        elif input_line[0] == '?':
            a, b = map(int, input_line[1:])
            a_root = find(a)
            b_root = find(b)
            if a_root != b_root: print('UNKNOWN')
            else: print(diff[a]-diff[b]) # diff[a]는 root무게-a무게이고, diff[b]는 root무게-b무게이므로 diff[a]-diff[b] 해야 정답이 나온다.