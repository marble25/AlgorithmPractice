from copy import deepcopy
import sys, time

input = sys.stdin.readline


class pos:
    def __init__(self, x, y):
        self.x = x
        self.y = y


def dfs(x, y):
    global zeroCnt
    for a in range(4):
        toGO = pos(x + direction[a].x, y + direction[a].y)
        if 0 <= toGO.x < bound.x and 0 <= toGO.y < bound.y and tempArr[toGO.x][toGO.y] == 0:
            zeroCnt -= 1
            tempArr[toGO.x][toGO.y] = 2
            dfs(toGO.x, toGO.y)
    return

start = time.time()

direction = [pos(1, 0), pos(0, -1), pos(-1, 0), pos(0, 1)]
bound = list(map(int, input().split()))
bound = pos(bound[0], bound[1])
arr = []
for i in range(bound.x):
    arr.append(list(map(int, input().split(' '))))
twoList = []
zeroList = []
for i in range(bound.x):
    for j in range(bound.y):
        if arr[i][j] == 2:
            twoList.append(pos(i, j))
        if arr[i][j] == 0:
            zeroList.append(pos(i, j))
result = 0
for w1 in zeroList:
    for w2 in zeroList:
        for w3 in zeroList:
            if w1 == w2 or w1 == w3 or w2 == w3:
                continue
            tempArr = deepcopy(arr)
            tempArr[w1.x][w1.y] = 1
            tempArr[w2.x][w2.y] = 1
            tempArr[w3.x][w3.y] = 1
            zeroCnt = len(zeroList) - 3
            for i in twoList:
                dfs(i.x, i.y)
            result = max(result, zeroCnt)
print(result)

print(time.time() - start)