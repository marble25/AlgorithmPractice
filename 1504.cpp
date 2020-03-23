//
// Created by marble on 20. 3. 23..
//

// 어렵지 않은 플로이드 와샬 알고리즘 문제였지만 작은 조건들에 주의해야 했던 문제

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string.h>
#include <string>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, e;
    cin >> n >> e;

    int dis[805][805] = {0};
    int x, y, z;
    int mid1, mid2;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            dis[i][j] = 987654321; // 거리를 모두 큰 값으로 초기화
        }
        dis[i][i] = 0; // 자기 자신과의 거리는 0으로 초기화
    }

    for(int i=0;i<e;i++) {
        cin >> x >> y >> z;
        dis[x-1][y-1] = z;
        dis[y-1][x-1] = z;
    }
    cin >> mid1 >> mid2;

    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(dis[i][k] + dis[k][j] < dis[i][j]) { // i에서 k를 거쳐서 j를 가는 것이 현재까지의 최소 거리보다 짧을 때 업데이트
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    if((dis[0][mid1-1] == 987654321 || dis[mid1-1][mid2-1] == 987654321 || dis[mid2-1][n-1] == 987654321) &&
       (dis[0][mid2-1] == 987654321 || dis[mid2-1][mid1-1] == 987654321 || dis[mid1-1][n-1] == 987654321)) { // mid1->mid2로 가는 경로와 mid2->mid1으로 가는 경로 중 둘 다 없을 경우
        cout << -1 << '\n';
        return 0;
    }
    int result = min(dis[0][mid1-1] + dis[mid1-1][mid2-1] + dis[mid2-1][n-1],
                     dis[0][mid2-1] + dis[mid2-1][mid1-1] + dis[mid1-1][n-1]); // 두 경로 중 최솟값을 넣어줌
    cout << result << '\n';

    return 0;
}