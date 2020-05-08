//
// Created by marble on 20. 5. 8..
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

// 0 : 시작 state
// 21 : 끝 state
// 25 : 가운데 state


int arr[10];
int map[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0, 13, 16, 19, 25, 22, 24, 30, 35, 28, 27, 26};
int linked[35] = {0}; // 빨간 화살표
int direct[35] = {0}; // 파란 화살표
int horse[4] = {0};
int current_map[35] = {0};
int ans = INT32_MIN;

void f(int idx, int score) {
    if(idx == 10) {
        ans = max(ans, score);
        return;
    }
    for(int i=0;i<4;i++) {
        int current = horse[i];
        if(current == 21) continue; // 이미 끝 상태면 더 진행 안함

        if(direct[horse[i]] != 0) { // 파란색 화살표가 있으면 파란색으로 진행
            horse[i] = direct[horse[i]];
        } else { // 아니면 빨간색으로 진행
            horse[i] = linked[horse[i]];
        }
        for(int j=1;j<arr[idx];j++) { // 전체에서 한번 뺀 횟수만큼 화살표 진행
            if(horse[i] == 21) break; // 끝 상태 도달하면 break
            horse[i] = linked[horse[i]];
        }
        if(current_map[horse[i]] != 0 && horse[i] != 21) { // 말이 이동 마치는 칸에 다른 말 있으면 못고름 (but 끝 상태는 가능)
            horse[i] = current;
            continue;
        }

        current_map[current] = 0;
        current_map[horse[i]] = 1; // 현재 도달한 상태로 바궈줌
        f(idx+1, score + map[horse[i]]);

        current_map[current] = 1; // 기존 상태로 바꿔줌
        current_map[horse[i]] = 0;
        horse[i] = current;
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0;i<10;i++) {
        cin >> arr[i];
    }

    for(int i=0;i<21;i++) {
        linked[i] = i+1;
    }
    linked[21] = -1;

    linked[22] = 23;
    linked[23] = 24;
    linked[24] = 25;
    linked[25] = 28;

    linked[26] = 27;
    linked[27] = 25;

    linked[28] = 29;
    linked[29] = 20;

    linked[30] = 31;
    linked[31] = 32;
    linked[32] = 25;

    direct[5] = 22;
    direct[10] = 26;
    direct[15] = 30;

    f(0, 0);
    cout << ans;

    return 0;
}