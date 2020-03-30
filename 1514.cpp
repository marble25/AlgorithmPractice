//
// Created by marble on 20. 3. 30..
//

// 너무나도 고민을 많이 해서 돌아가고 돌아가다가 결국 문제 해결 방법을 찾아본 문제
// 다차원 배열을 사용한 top-down 방식도 항상 고려해 봐야겠다.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

int n;
int dp[105][10][10][10][2]; // dp[pos][i][j][k][dir] : pos는 디스크 인덱스, i, j, k는 각각 pos, pos+1, pos+2 위치에 더해진 값, dir은 왼쪽 오른쪽
char arr[105];
char goal[105];

int f(int pos, int x, int y, int z, int dir) {
    if(pos == n) return 0;
    int &ret = dp[pos][x][y][z][dir];
    if(ret != -1) return ret;
    if((arr[pos] + x) % 10 == goal[pos]) return min(f(pos+1, y, z, 0, 0), f(pos+1, y, z, 0, 1)); // 목표에 도달하면 왼쪽으로 돌리는 것과 오른쪽으로 돌리는 것 중 min값 호출
    ret = INT16_MAX;
    if(dir == 0) {
        for(int i=1;i<=3;i++) {
            ret = min(ret, 1 + f(pos, (x+i+30)%10, y, z, dir)); // x만 움직임
            ret = min(ret, 1 + f(pos, (x+i+30)%10, (y+i+30)%10, z, dir)); // xy 움직임
            ret = min(ret, 1 + f(pos, (x+i+30)%10, (y+i+30)%10, (z+i+30)%10, dir)); // xyz 움직임
        }
    } else {
        for(int i=1;i<=3;i++) {
            ret = min(ret, 1 + f(pos, (x-i+30)%10, y, z, dir)); // x만 움직임
            ret = min(ret, 1 + f(pos, (x-i+30)%10, (y-i+30)%10, z, dir)); // xy 움직임
            ret = min(ret, 1 + f(pos, (x-i+30)%10, (y-i+30)%10, (z-i+30)%10, dir)); // xyz 움직임
        }
    }

    return ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        arr[i] -= '0';
    }
    for(int i=0;i<n;i++) {
        cin >> goal[i];
        goal[i] -= '0';
    }

    memset(dp, -1, sizeof(dp));
    cout << min(f(0, 0, 0, 0, 0), f(0, 0, 0, 0, 1));

    return 0;
}