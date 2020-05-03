//
// Created by marble on 20. 5. 3..
//

// 간단한 시뮬레이션 문제
// 조건만 잘 따져주면 쉽게 맞출 수 있는 문제이다.

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

int r, c, t;
int map[55][55] = {0};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void diffusion() {
    int temp_map[55][55] = {0};

    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            int adder = (map[i][j]) / 5;
            for(int k=0;k<4;k++) {
                int moved_x = i + dx[k];
                int moved_y = j + dy[k];

                if(moved_x < 1 || moved_x > r) continue; // 맵 벗어나는지
                if(moved_y < 1 || moved_y > c) continue; // 맵 벗어나는지
                if(map[moved_x][moved_y] == -1) continue; // 공기청정기인 칸은 pass

                map[i][j] -= adder; // 확산
                temp_map[moved_x][moved_y] += adder; // 추가되는 먼지는 따로 저장
            }
        }
    }

    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            map[i][j] += temp_map[i][j]; // 추가되는 먼지까지 합산
        }
    }
}

void air_clean_up(int x, int y) { // 위쪽 공기청정기
    for(int i=x-1;i>1;i--) {
        map[i][1] = map[i-1][1];
    }
    for(int j=1;j<c;j++) {
        map[1][j] = map[1][j+1];
    }
    for(int i=1;i<x;i++) {
        map[i][c] = map[i+1][c];
    }
    for(int j=c;j>2;j--) {
        map[x][j] = map[x][j-1];
    }
    map[x][2] = 0;
}

void air_clean_down(int x, int y) { // 아래쪽 공기청정기
    for(int i=x+1;i<r;i++) {
        map[i][1] = map[i+1][1];
    }
    for(int j=1;j<c;j++) {
        map[r][j] = map[r][j+1];
    }
    for(int i=r;i>x;i--) {
        map[i][c] = map[i-1][c];
    }
    for(int j=c;j>2;j--) {
        map[x][j] = map[x][j-1];
    }
    map[x][2] = 0;
}

void simulate(pair<int, int> start, pair<int, int> end) {
    diffusion();
    air_clean_up(start.first, start.second);
    air_clean_down(end.first, end.second);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    pair<int, int> start = {-1, -1};
    pair<int, int> end = {-1, -1};
    cin >> r >> c >> t;
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            cin >> map[i][j];
            if(map[i][j] == -1) {
                if(start.first == -1 && start.second == -1) start = {i, j};
                else end = {i, j};
            }
        }
    }

    for(int i=0;i<t;i++) {
        simulate(start, end);
    }

    int ans = 0;
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=c;j++) {
            if(map[i][j] > 0) {
                ans += map[i][j];
            }
        }
    }

    cout << ans;


    return 0;
}