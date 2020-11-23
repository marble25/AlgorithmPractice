// break문 하나로 정답이 갈린 문제
// 항상 꼼꼼하게...

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

int T;
int n, m;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    while(T--) {
        cin >> n >> m;

        vector<pair<int, int>> v;
        int checked[1005] = {0};

        for(int i=0;i<m;i++) {
            int x, y;
            cin >> x >> y;
            v.push_back({y, x});
        }

        sort(v.begin(), v.end()); // 뒤의 범위를 기준으로 정렬
        int cnt = 0;

        for(int i=0;i<m;i++) {
            int start = v[i].second, end = v[i].first;
            for(int j=start;j<=end;j++) {
                if(checked[j] == 0) { // 비어있으면 채워넣기
                    cnt++;
                    checked[j] = 1;
                    break;
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}