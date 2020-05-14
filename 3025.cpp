//
// Created by marble on 20. 5. 7..
//

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
int pointer_floor[35] = {0};
int pointer_direct[30005][35] = {0};

int calc(int row, int col) {
    char current_block = map[row][col];
    while(current_block != '.') {
        row--;
        current_block = map[row][col];
    }
    char under_block = map[row+1][col];
    if(row == r || under_block == 'X') { // 밑바닥이거나 아래칸이 벽일 때
        map[row][col] = 'O';
        if(row < pointer_floor[col]) { // 현재가 floor보다 높이 있으면 floor에 현재 row 대입
            pointer_floor[col] = row;
        }
        return row-1;
    } else if(under_block == 'O') {
        if(col-1 > 0 && map[row][col-1] == '.' && map[row+1][col-1] == '.') {
            calc(row, col-1);
        } else if(col+1 <= c && map[row][col+1] == '.' && map[row+1][col+1] == '.') {
            calc(row, col+1);
        } else {
            map[row][col] = 'O';
            if(row < pointer_floor[col]) {
                pointer_floor[col] = row;
            }
            return row-1;
        }
    } else {
        int re = calc(pointer_direct[row][col], col);
        if(re != -1) {
            pointer_direct[row][col] = re;
        }
    }
    return -1;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;

    // 입력
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            cin >> map[i][j];
        }
    }

    // 쌓을 수 있는 가장 밑바닥 설정
    for(int j=1;j<=c;j++) {
        pointer_floor[j] = r+1;
        int i=1;
        for(;i<=r;i++) {
            if(map[i][j] == 'X' && pointer_floor[j] == r+1) { // 밑바닥에 도달했다면
                pointer_floor[j] = i; // 밑바닥 포인터 설정
                break;
            }
        }
        int floor_value = r;
        for(i=r;i>=1;i--) {
            if(map[i][j] == '.') {
                pointer_direct[i][j] = floor_value;
            } else {
                floor_value = i-1;
            }

        }
    }

    cin >> n;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;

        calc(1, x);
    }

    for(int k=1;k<=r;k++) {
        for(int j=1;j<=c;j++) {
            cout << map[k][j];
        }
        cout << "\n";
    }




    return 0;
}