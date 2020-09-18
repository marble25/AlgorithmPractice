//
// Created by marble on 20. 9. 18..
//

// 이렇게까지 안해도 시간 초과는 안 나올거라고 알고 있었지만, 최대한 시간을 줄여서 풀고 싶었다.
// 단순히 Brute Force로도 풀 수 있는 문제

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

int knum, n;
int arr[100][3] = {0};
int dp[100][100][100] = {0};
int ans = 1 << 30;

vector<int> x, y, z;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> knum;
    for(int i=0;i<n;i++) {
        for(int j=0;j<3;j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<n;i++) {
        x.push_back(arr[i][0]);
        y.push_back(arr[i][1]);
        z.push_back(arr[i][2]);
    }

    // 정렬 후 중복 제거
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    x.erase(unique(x.begin(), x.end()), x.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    z.erase(unique(z.begin(), z.end()), z.end());

    // x에서 몇 번째, y에서 몇 번째, z에서 볓 번째인지 알아내서 dp에 표시
    for(int i=0;i<n;i++) {
        int a, b, c;
        for(int j=0;j<x.size();j++) {
            if(x[j] >= arr[i][0]) {
                a = j;
                break;
            }
        }

        for(int j=0;j<y.size();j++) {
            if(y[j] >= arr[i][1]) {
                b = j;
                break;
            }
        }

        for(int j=0;j<z.size();j++) {
            if(z[j] >= arr[i][2]) {
                c = j;
                break;
            }
        }
        dp[a][b][c] = 1;
    }

    // dp에서 누적 개수 표시
    for(int i=1;i<n;i++) {
        dp[i][0][0] += dp[i-1][0][0];
        dp[0][i][0] += dp[0][i-1][0];
        dp[0][0][i] += dp[0][0][i-1];
    }

    for(int i=1;i<n;i++) {
        for(int j=1;j<n;j++) {
            dp[i][j][0] += dp[i-1][j][0] + dp[i][j-1][0] - dp[i-1][j-1][0];
            dp[i][0][j] += dp[i-1][0][j] + dp[i][0][j-1] - dp[i-1][0][j-1];
            dp[0][i][j] += dp[0][i-1][j] + dp[0][i][j-1] - dp[0][i-1][j-1];
        }
    }

    for(int i=1;i<x.size();i++) {
        for(int j=1;j<y.size();j++) {
            for(int k=1;k<z.size();k++) {
                dp[i][j][k] += dp[i-1][j][k] + dp[i][j-1][k] + dp[i][j][k-1]
                               - dp[i-1][j-1][k] - dp[i][j-1][k-1] - dp[i-1][j][k-1]
                               + dp[i-1][j-1][k-1];
            }
        }
    }

    for(int i=0;i<x.size();i++) {
        for(int j=0;j<y.size();j++) {
            for(int k=0;k<z.size();k++) {
                if(dp[i][j][k] >= knum) { // 누적 개수 합이 입력받은 k보다 크면 ans 업데이트
                    ans = min(ans, x[i] + y[j] + z[k]);
                    break;
                }
            }
        }
    }

    cout << ans;

}