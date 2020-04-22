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

int n, m, k, t;
int map[305][305] = {0};
queue<pair<int, int>> q;
vector<pair<int, int>> check;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k >> t;
    for(int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        q.push({x, y});
    }

    for(int i=0;i<k;i++) {
        int x, y;
        cin >> x >> y;
        check.push_back({x, y});
    }

    for(int i=1;i<=t;i++) {
        int q_size = q.size();
        while(q_size--) {
            int x = q.front().first, y = q.front().second;
            for(int j=0;j<8;j++) {
                int m_x = x + dx[j];
                int m_y = y + dy[j];
                if(m_x < 0 || m_y < 0 || m_x >= n || m_y >= n) continue;
                if(map[m_x][m_y] == 0) {
                    q.push({m_x, m_y});
                    map[m_x][m_y] = 1;
                }

            }
        }
    }
    bool is_clean_needed = false;
    for(int i=0;i<k;i++) {
        int x = check[i].first, y = check[i].second;
        if(map[x][y] != 0) {
            is_clean_needed = true;
            break;
        }
    }

    cout << (is_clean_needed ? "YES" : "NO") << "\n";

    return 0;
}