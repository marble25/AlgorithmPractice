//
// Created by marble on 20. 3. 24..
//

// 아직 c++에 익숙해지지 못했나보다...
// 더 연습해서 익숙해져야겠다.

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
int n, m;
vector<int> v[10001];
int arr[10001] = {0};
int visited[10001];
void dfs(int root, int x) {
    arr[root] ++; // 루트에서 갈 수 있는 컴퓨터 갯수 증가
    visited[x] = 1;
    for(int & it : v[x]) {
        if(visited[it] == 0) dfs(root, it);
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x, y;
    cin >> n >> m;

    for(int i=0;i<m;i++) {
        cin >> x >> y;
        v[y].push_back(x);
    }
    int max_val = 0;
    vector<int> indexes;
    for(int i=1;i<=n;i++) {
        memset(visited, 0, sizeof(visited)); // visited를 0으로 초기화
        dfs(i, i); // i를 루트 노드로 두는 dfs 시작
        if(arr[i] > max_val) { // max보다 크면 업데이트
            max_val = arr[i];
            indexes.clear();
            indexes.push_back(i);
        } else if(arr[i] == max_val) { // max값과 같으면 indexes push
            indexes.push_back(i);
        }
    }
    for(int & it : indexes) {
        cout << it << ' ';
    }
    return 0;
}