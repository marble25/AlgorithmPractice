# project : baekjoon python algorithm practice
# user : marble
# date : 20. 3. 15.
# time : 오후 10:28
# problem : https://www.acmicpc.net/problem/1976
# problem type : Disjoint-set

# 기초적인 Disjoint-Set 문제

def find(u):
    if parent[u] == u: return u
    parent[u] = find(parent[u])
    return parent[u]

def union(u, v):
    global parent, rank
    u_root = find(u)
    v_root = find(v)

    if u_root == v_root: return
    if rank[u_root] < rank[v_root]:
        parent[u_root] = v_root
    else:
        parent[v_root] = u_root

    if rank[u_root] == rank[v_root]:
        rank[u_root] += 1


import sys
n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

rank = [1 for i in range(n+1)]
parent = [i for i in range(n+1)]

for i in range(1, n+1):
    input_line = [0] + list(map(int, sys.stdin.readline().split()))
    for j in range(1, n+1):
        if input_line[j] == 1:
            union(i, j)

input_line = list(map(int, sys.stdin.readline().split()))
for i in range(1, m):
    if find(input_line[i-1]) != find(input_line[i]):
        print('NO')
        sys.exit(0)

print('YES')