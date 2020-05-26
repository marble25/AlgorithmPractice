// 상당히 난이도가 있었다.
// 어쩌면 쉽게 풀 수도 있었을 텐데...
// 더 깊게 생각할 수 있었으면 좋겠다.

//
// Created by marble on 20. 5. 27..
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
vector<pair<int, int>> a[2005];
int cnt[200005];
int ans[200005];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        a[y].push_back({x, i}); // 크기 배열에 새로운 변수 삽입
    }

    int smaller = 0;
    for(int i=1;i<=2000;i++) {
        for(int j=0;j<a[i].size();j++) { // 해당 개수를 다 돌면서 이 수보다 더 작은 수의 합에서 이 수보다 더 작은 수 중 같은 색인 것들을 뺀 값을 넣는다.
            ans[a[i][j].second] = smaller - cnt[a[i][j].first];
        }
        for(int j=0;j<a[i].size();j++) { // 해당 색깔의 더 작은 수 합 구함
            cnt[a[i][j].first] += i;
        }
        smaller += i * a[i].size(); // 더 작은 수들의 합을 구함
    }

    for(int i=0;i<n;i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}