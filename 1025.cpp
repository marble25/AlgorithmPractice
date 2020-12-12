//
// Created by marble on 20. 12. 13..
//

// 문제가 이해가 안되었을 뿐, 문제를 이해하고 나니 어렵지 않았던 문제

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
char arr[10][10] = {0};
int ans = -1;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    for(int i=0;i<n;i++) { // 시작점 x좌표
        for(int j=0;j<m;j++) { // 시작점 y좌표
            for(int ix=-n;ix<=n;ix++) { // x좌표의 차이
                for(int jx=-m;jx<=m;jx++) { // y좌표의 차이
                    if(ix == 0 && jx == 0) continue; // 동일한 칸을 반복하는 것을 방직

                    string s = "";
                    for(int k=0;k<=9;k++) { // 몇번 갈지를 결정
                        int cx = i + k * ix; // 현재 좌표
                        int cy = j + k * jx; // 현재 좌표

                        if(cx < 0 || cy < 0 || cx >= n || cy >= m) break; // 범위를 넘어가면 break
                        s.append(1, arr[cx][cy]);

                        int value = stoi(s);
                        int sqrt_value = sqrt(value);

                        if(value == sqrt_value * sqrt_value) {
                            ans = max(ans, value);
                        }
                    }
                }
            }
        }
    }

    cout << ans;

    return 0;
}