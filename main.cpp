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

pair<int, int> point[5];
pair<int, int> target[5];
int cnt = 0;
int checked[5][5] = {0};
int ans = 987654321;

char mp[6][6];


void calc_dist() {
    int temp = 0;
    for(int i=0;i<cnt;i++) {
        temp += abs(target[i].first - point[i].first) + abs(target[i].second - point[i].second);
    }


}

void select(int stage) {
    if(stage == cnt) {
        calc_dist();
        return;
    }

    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            if(checked[i][j] != 0) continue;
            target[stage] = {i, j};
            checked[i][j] = stage;
            select(stage+1);
            checked[i][j] = 0;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0;i<5;i++) {
        cin >> mp[i];
    }

    for(int j=0;j<5;j++) {
        for(int i=0;i<5;i++) {
            if(mp[i][j] == '*') {
                point[cnt++] = {i, j};
            }
        }
    }

    if(cnt == 1) {
        cout << 0;
        return 0;
    }



    return 0;
}