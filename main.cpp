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

int r, c, n;
char map[30005][35] = {0};
vector<int> map_floor[35];

void calc(int row, int col) {
    for (int j = 0; j < map_floor[col].size(); j++) {
        if (map_floor[col][j] < row) continue;

        int &f_x = map_floor[col][j];
        if (f_x == r + 1) {
            f_x = r;
            map[f_x][col] = 'O';
        } else if (map[f_x][col] == 'X') {
            f_x = f_x - 1;
            map[f_x][col] = 'O';
        } else if (map[f_x][col] == 'O') {
            if (map[f_x-1][col-1] == '.' && map[f_x][col - 1] == '.') {
                calc(f_x, col - 1);
            } else if (map[f_x-1][col+1] == '.' && map[f_x][col + 1] == '.') {
                calc(f_x, col + 1);
            } else {
                f_x = f_x - 1;
                map[f_x][col] = 'O';
            }
        }
        break;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;

    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            cin >> map[i][j];
        }
    }

    for(int j=1;j<=c;j++) {
        int start = -1;
        bool flag = false;
        for(int i=1;i<=r;i++) {
            if(map[i][j] == 'X' && !flag) {
                flag = true;
                start = i;
            } else if(flag){
                flag = false;
                map_floor[j].push_back(start);
            }
        }
        if(flag) {
            map_floor[j].push_back(start);
        } else {
            map_floor[j].push_back(r+1);
        }
    }

    cin >> n;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;

        calc(1, x);
    }

    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }



    return 0;
}