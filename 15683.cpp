//
// Created by marble on 20. 4. 8..
//

// 조건이 굉장히 많았지만 n, m이 크지 않아 브루트 포스로 푼 문제
// 소스코드 자체는 굉장히 길어졌다.

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

int n, m;
int original_map[8][8];
int map[8][8];
string directions[6][4] = { // left, right, up, down 순서
        {"0000", "0000", "0000", "0000"},
        {"1000", "0100", "0010", "0001"},
        {"1100", "0011", "0000", "0000"},
        {"1010", "1001", "0101", "0110"},
        {"1110", "0111", "1011", "1101"},
        {"1111", "0000", "0000", "0000"},
};
int cctv_cnt = 0;
int min_area = INT32_MAX;
pair<pair<int, int>, pair<int, int>> cctv[8]; // (x, y), (CCTV 종류, 방향)

void clear_map() { // 처음에 입력받은 맵으로 초기화해주는 함수
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            map[i][j] = original_map[i][j];
        }
    }
}

void left_check(int x, int y) { // 왼쪽으로 벽 전까지 cctv 영역을 채워주는 함수
    for(int i=y-1;i>=0;i--) {
        if(map[x][i] == 6) {
            break;
        }
        map[x][i] = -1;
    }
}

void right_check(int x, int y) { // 오른쪽으로 벽 전까지 cctv 영역을 채워주는 함수
    for(int i=y+1;i<m;i++) {
        if(map[x][i] == 6) {
            break;
        }
        map[x][i] = -1;
    }
}

void up_check(int x, int y) { // 위쪽으로 벽 전까지 cctv 영역을 채워주는 함수
    for(int i=x-1;i>=0;i--) {
        if(map[i][y] == 6) {
            break;
        }
        map[i][y] = -1;
    }
}

void down_check(int x, int y) { // 아래쪽으로 벽 전까지 cctv 영역을 채워주는 함수
    for(int i=x+1;i<n;i++) {
        if(map[i][y] == 6) {
            break;
        }
        map[i][y] = -1;
    }
}

void check_map() {
    clear_map();
    for(int i=0;i<cctv_cnt;i++) {
        pair<pair<int, int>, pair<int, int>> p = cctv[i];
        int type = p.second.first;
        int dir = p.second.second;

        int x = p.first.first, y = p.first.second;
        string dir_str = directions[type][dir]; // dir_str을 가져옴
        if(dir_str == "0000") {
            continue;
        }

        if(dir_str[0] == '1') { // 왼쪽 체크
            left_check(x, y);
        }
        if(dir_str[1] == '1') { // 오른쪽 체크
            right_check(x, y);
        }
        if(dir_str[2] == '1') { // 위 체크
            up_check(x, y);
        }
        if(dir_str[3] == '1') { // 아래 체크
            down_check(x, y);
        }
    }

    int left_cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(map[i][j] == 0) { // 사각지대 카운트
                left_cnt ++;
            }
        }
    }
    min_area = min(min_area, left_cnt); // min_area를 min값으로 업데이트
}

void brute_force(int index) {
    if(index == cctv_cnt) { // 끝에 도달하면 사각지대 체크
        check_map();
        return;
    }

    pair<pair<int, int>, pair<int, int>> p = cctv[index];
    int type = p.second.first;
    if(type == 5) { // 한 가지 경우만 가능
        p.second.second = 0;
        cctv[index] = p;
        brute_force(index+1);
    } else if(type == 2) { // 두 가지 경우만 가능
        for(int i=0;i<2;i++) {
            p.second.second = i;
            cctv[index] = p;
            brute_force(index+1);
        }
    } else {
        for(int i=0;i<4;i++) { // 4가지 경우 가능
            p.second.second = i;
            cctv[index] = p;
            brute_force(index+1);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;


    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> original_map[i][j];
            if(original_map[i][j] != 0 && original_map[i][j] != 6) { // CCTV이면 cctv 배열에 추가
                cctv[cctv_cnt++] = make_pair(make_pair(i, j), make_pair(original_map[i][j], 0));
            }
        }
    }

    brute_force(0);
    cout << min_area;
    return 0;
}