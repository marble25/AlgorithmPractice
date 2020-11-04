//
// Created by marble on 20. 11. 4..
//

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

int n, m;
int arr[1030][1030] = {0};
int sum[1030][1030] = {0};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            sum[i][j] = arr[i][j] + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
        }
    }

    for(int i=0;i<m;i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] << "\n";
    }

    return 0;
}