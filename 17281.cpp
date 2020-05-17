//
// Created by marble on 20. 5. 17..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <string.h>
using namespace std;

int n;
int re[9][50] = {0};
int ans = INT32_MIN;

void swap(int **a, int **b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}

int calc() {
    int base[3] = {0};
    int score = 0;
    int out = 0;

    int hitter = 0;
    for(int i=0;i<n;i++) {
        while(true) {
            if(re[hitter][i] == 0) { // 아웃이면 아웃 카운트 증가
                out++;
            } else if(re[hitter][i] == 1) { // 안타면 한 칸씩 진루하고 3루수는 득점
                score += base[2];
                base[2] = base[1];
                base[1] = base[0];
                base[0] = 1;
            } else if(re[hitter][i] == 2) { // 2루타면 두 칸씩 진루하고 2, 3루수는 득점
                score += base[2] + base[1];
                base[2] = base[0];
                base[1] = 1;
                base[0] = 0;
            } else if(re[hitter][i] == 3) { // 3루타면 3칸씩 진루하고 1, 2, 3루수는 득점
                score += base[2] + base[1] + base[0];
                base[2] = 1;
                base[1] = 0;
                base[0] = 0;
            } else if(re[hitter][i] == 4) { // 홈런이면 타자와 1, 2, 3루수 득점, 베이스 비움
                score += base[2] + base[1] + base[0] + 1;
                base[2] = 0;
                base[1] = 0;
                base[0] = 0;
            }
            hitter ++;
            if(hitter == 9) { // 8번 타자까지 다 쳤다면 다음은 1번 타자
                hitter = 0;
            }

            if(out == 3) { // 3 아웃이 되었을 때 베이스 비우고 다음 이닝
                base[2] = 0;
                base[1] = 0;
                base[0] = 0;
                out = 0;
                break;
            }


        }
    }

    return score;
}

void perm(int stage) {
    if(stage == 8) {
        int score = calc();
        ans = max(score, ans);
        return;
    }

    if(stage == 3) {
        perm(4);
    } else {
        for(int i=stage;i<9;i++) {
            if(i == 3) continue;
            swap(re[stage], re[i]);
            perm(stage+1);
            swap(re[stage], re[i]);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<9;j++) {
            cin >> re[j][i];
        }
    }

    swap(re[0], re[3]); // 1번 선수를 4번 타자로 못박음

    perm(0);
    cout << ans;

    return 0;
}