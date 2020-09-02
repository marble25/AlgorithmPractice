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
int arr[20][20];
int temp[20][20];
int checked[20][20];
int ans[20][20];

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

void toggle(int x, int y) {
    for(int i=0;i<5;i++) {
        int mx = x+dx[i], my=y+dy[i];
        if(mx < 0 || my < 0 || mx >= m || my >= n) {
            continue;
        }
        temp[mx][my] = 1-temp[mx][my];
    }
}

int func(int i) {
    int cnt = 0;
    memcpy(temp, arr, sizeof(arr));
    memset(checked, 0, sizeof(checked));

    for(int k=0;k<n;k++) { // 가장 첫 줄에 나올 수 있는 모든 경우의 수를 다 계산해봄
        if(i & (1 << k)) { // k번째 열을 뒤집는 경우
            checked[0][k] = 1; // k번째를 뒤집었다고 체크
            toggle(0, k);
            cnt++;
        }
    }

    for(int j=1;j<m;j++) { // 두 번째 줄부터
        for(int k=0;k<n;k++) {
            if(temp[j-1][k] == 1) { // 이전 줄이 1인 경우 현재 칸을 뒤집어줌
                checked[j][k] = 1;
                toggle(j, k);
                cnt++;
            }
        }
    }

    // 처음부터 돌리면서 안뒤집힌 붕어빵이 있는지 체크
    for(int j=0;j<m;j++) {
        for(int k=0;k<n;k++) {
            if(temp[j][k] == 1) {
                return 987654321;
            }
        }
    }
    return cnt;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }

    int min_value = 987654321;
    for(int i=0;i<(1<<n);i++) { // 첫 줄을 뒤집을 수 있는 모든 경우의 수 나열
        int ret = func(i);
        if(ret < min_value) { // 더 작은 값이 있으면 업데이트
            min_value = ret;
            memcpy(ans, checked, sizeof(checked));
        }
    }

    if(min_value == 987654321) {
        cout << "IMPOSSIBLE" << "\n";
    } else {
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cout << ans[i][j];
                if(j != n-1) {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}