//
// Created by marble on 20. 4. 30..
//

// 간단하게 풀어본 시뮬레이션 문제

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

int n, m, x, y, k;
int map[25][25] = {0};
int command = 0;
int dice[6] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    cin >> x >> y;
    cin >> k;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0;i<k;i++) {
        cin >> command;
        if(command == 1) {
            if (y + 1 >= m) continue;
            y++;
            int temp = dice[5];
            dice[5] = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[3];
            dice[3] = temp;
        } else if(command == 2) {
            if (y - 1 < 0) continue;
            y--;
            int temp = dice[3];
            dice[3] = dice[4];
            dice[4] = dice[1];
            dice[1] = dice[5];
            dice[5] = temp;
        } else if(command == 3) {
            if (x - 1 < 0) continue;
            x--;
            int temp = dice[0];
            dice[0] = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[3];
            dice[3] = temp;
        } else if(command == 4) {
            if (x + 1 >= n) continue;
            x++;
            int temp = dice[3];
            dice[3] = dice[2];
            dice[2] = dice[1];
            dice[1] = dice[0];
            dice[0] = temp;
        }

        if(map[x][y] == 0) {
            map[x][y] = dice[3];
        } else {
            dice[3] = map[x][y];
            map[x][y] = 0;
        }

        cout << dice[1] << '\n';

    }


    return 0;
}