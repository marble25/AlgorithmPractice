//
// Created by marble on 20. 4. 12..
//

// 때론 이런 간단한 문제가 더 어렵게 느껴진다.
// 확률 문제라서 그런가..

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

int cards[11] = {0}; // card의 개수를 세어 놓는다.
int score[20] = {0}; // 앞에서부터 해당 score인 경우의 수를 세어놓는다.

int calc_score(int x, int y) { // 점수 계산하는 함수
    int idx = 0;
    for(int i=10;i>=1;i--) {
        if(x == i && y == i) {
            break;
        }
        idx ++;
    }
    if(idx > 9) {
        for(int i=9;i>=0;i--) {
            if((x+y) % 10 == i) {
                break;
            }
            idx ++;
        }
    }
    return idx;
}
void calc(int x, int y) {
    for(int i=1;i<=10;i++) {
        cards[i] = 2;
    }
    cards[x] --;
    cards[y] --;

    for(int i=1;i<=10;i++) {
        if(cards[i] == 0) continue; // 남은 카드가 없을 때 continue
        cards[i] --;
        for(int j=1;j<=10;j++) {
            if(cards[j] == 0) continue; // 남은 카드가 없을 때 continue
            int idx = calc_score(i, j);
            score[idx] += (cards[i]+1) * cards[j]; // 이 경우가 나올 수 있는 방법수만큼 더해줌
        }
        cards[i] ++;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    calc(a, b);
    int idx = calc_score(a, b);

    int total = 0;
    double p = 0.0;
    for(int i=0;i<20;i++) {
        total += score[i];
        if(idx < i) { // 더 낮은 점수라면 경우의 수를 더해줌
            p += score[i];
        }
    }
    p /= (double)total;

    cout << fixed;
    cout.precision(3);
    cout << p;

    return 0;
}