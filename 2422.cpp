//
// Created by marble on 20. 10. 14..
//

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

int n, m;
int combination[205][205] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        combination[x][y] = 1;
        combination[y][x] = 1;
    }

    int cnt = 0;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(combination[i][j] == 1) continue;
            for(int k=j+1;k<=n;k++) {
                if(combination[j][k] == 1) continue;
                if(combination[i][k] == 1) continue;

                cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}