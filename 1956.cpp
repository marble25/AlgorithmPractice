//
// Created by marble on 20. 9. 11..
//

// 쉽게 풀 수 있었던 문제
// 플루이드 와샬 알고리즘을 생각해 내서 바로 적용했다.


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

int v, e;
int linked[405][405] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> v >> e;
    for(int i=1;i<=v;i++) { // 초기값을 무한대로 초기화
        for(int j=1;j<=v;j++) {
            linked[i][j] = 987654321;
        }
    }

    for(int i=0;i<e;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        linked[a][b] = c;
    }

    for(int k=1;k<=v;k++) { // 플루이드 와샬 알고리즘으로 거리 정보를 업데이트
        for(int i=1;i<=v;i++) {
            for(int j=1;j<=v;j++) {
                if(linked[i][k] + linked[k][j] < linked[i][j]) {
                    linked[i][j] = linked[i][k] + linked[k][j];
                }
            }
        }
    }
    int total = 987654321;
    for(int i=1;i<=v;i++) {
        for(int j=1;j<=v;j++) {
            if(linked[i][j] != 987654321 && linked[j][i] != 987654321) { // 어떤 점으로 가는 경로도 있고 오는 경로도 있다면 사이클이 존재한다
                total = min(total, linked[i][j] + linked[j][i]);
            }
        }
    }

    if(total == 987654321) cout << -1;
    else cout << total;


    return 0;
}