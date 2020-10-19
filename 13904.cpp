//
// Created by marble on 20. 10. 19..
//

// 오랜만에 풀어본 그리디 문제
// 확실히 증명하는 것이 아직도 어렵다

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

int n;
int res[1001] = {0};
vector<pair<int, int>> scores;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;

        scores.push_back({y, x});
    }

    sort(scores.begin(), scores.end()); // 점수가 큰 순서대로 정렬
    for(int i=n-1;i>=0;i--) {
        if(res[scores[i].second] == 0) { // 해당 마감일이 비어있으면 채워넣음(뒤에서부터 채워넣는것이 이득)
            res[scores[i].second] = scores[i].first;
        } else { // 해당 마감일이 차있으면
            for(int j=scores[i].second-1;j>=1;j--) { // 앞으로 가면서 비어있는 배열에 채워넣음
                if(res[j] == 0) {
                    res[j] = scores[i].first;
                    break;
                }
            }
        }
    }

    int sum = 0;
    for(int i=1;i<=1000;i++) { // 전체 날짜를 카운트
        sum += res[i];
    }

    cout << sum;

    return 0;
}