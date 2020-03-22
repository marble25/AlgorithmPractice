# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 15.
# time : 오후 10:09
# problem : https://www.acmicpc.net/problem/1717
# problem type : Disjoint-set

# Disjoint의 기초 예제

def find(u):
    if parent[u] == u: return u # 루트 노드이면 return
    parent[u] = find(parent[u]) # parent 노드를 업데이트 시킴
    return parent[u]

def union(u, v):
    global parent
    u_root = find(u)
    v_root = find(v)
    if u_root == v_root: return # 같은 집합에 있으면 합칠 필요가 없으므로 return
    if rank[u_root] < rank[v_root]: # u의 깊이가 더 작으면 u를 v쪽으로 합침
        parent[u_root] = v_root
    else: # u의 깊이가 v보다 더 크거나 같으면 v를 u쪽으로 합침
        parent[v_root] = u_root

    if rank[u_root] == rank[v_root]: # 깊이가 같으면 u의 깊이가 하나 증가
        rank[u_root] += 1

import sys
n, m = map(int, sys.stdin.readline().split())
parent = [i for i in range(n+2)]
rank = [1 for _ in range(n+2)]

for i in range(m):
    x, a, b = map(int, sys.stdin.readline().split())
    if x == 0:
        union(a, b)
    elif x == 1:
        a_root = find(a)
        b_root = find(b)
        if a_root == b_root: print('YES')
        else: print('NO')