//
// Created by 이지호 on 21. 2. 9..
//

// 예전에 python으로 풀었던 문제를 간단히 다시 풀어보았다.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <string.h>
using namespace std;

int w[55][55][55] = {0};

int f(int x, int y, int z) {
    if(x <= 0 || y <= 0 || z <= 0) return w[x][y][z] = 1;
    if(x > 20 || y > 20 || z > 20) return w[x][y][z] = f(20, 20, 20);
    if(w[x][y][z]) return w[x][y][z];
    else if(x < y && y < z) return w[x][y][z] = f(x, y, z-1) + f(x, y-1, z-1) - f(x, y-1, z);
    else return w[x][y][z] = f(x-1, y, z) + f(x-1, y-1, z) + f(x-1, y, z-1) - f(x-1, y-1, z-1);
}
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x, y, z;
    for(int i=0;i<=50;i++) {
        for(int j=0;j<=50;j++) {
            for(int k=0;k<=50;k++) {
                w[i][j][k] = f(i, j, k);
            }
        }
    }
    while(true) {
        cin >> x >> y >> z;
        if(x == -1 && y == -1 && z == -1) break;
        if(x < 0 || y < 0 || z < 0) printf("w(%d, %d, %d) = %d\n", x, y, z, 1);
        else printf("w(%d, %d, %d) = %d\n", x, y, z, w[x][y][z]);
    }

    return 0;
}