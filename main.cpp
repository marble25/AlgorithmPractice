// 정렬을 통해서 간단히 풀 수 있었다.
// 다만 시간이 생각보다 많이 나와서 아쉽다.

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
vector<int> v[100005];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        v[y].push_back(x);
    }

    for(int i=1;i<=n;i++) { // 같은 레인에 있는 점끼리 정렬
        sort(v[i].begin(), v[i].end());
    }

    long long dis = 0;
    for(int i=1;i<=n;i++) {
        int sz = v[i].size();
        for(int j=0;j<sz;j++) {
            if(j == 0) { // 처음이라면 그 다음점과의 거리만 더해줌
                if(sz > 1) {
                    dis += v[i][1] - v[i][0];
                }
            } else if(j == sz - 1) { // 마지막이라면 그 전 점과의 거리만 더해줌
                dis += v[i][sz-1] - v[i][sz-2];
            } else { // 아니면 전 점과 다음 점 중 가까운 점을 선택
                dis += min(v[i][j] - v[i][j-1], v[i][j+1] - v[i][j]);
            }
        }
    }

    cout << dis;

    return 0;
}