//
// Created by marble on 20. 5. 30..
//

// 한 문장을 빠뜨려서 계속 틀렸던 문제
// 알고리즘 검증을 똑바로 해야 한다

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

int t;
int f;
map<string, int> mp;
int parent[200005];
int rk[200005];
int sz[200005];

int find(int x) { // 조상을 찾는 함수
    int y = x;
    while(parent[y] != y) { // 부모가 자기 자신일 때까지(조상) 올라감
        y = parent[y];
    }
    parent[x] = y; // 현재 노드의 부모를 조상으로 설정
    return y;
}

int merge(int x, int y) {
    int ret = 0;
    x = find(x);
    y = find(y);
    if(x == y) return sz[x]; // 같은 조상이면 merge 진행 안함
    if(rk[x] < rk[y]) { // x의 차수가 y의 차수보다 작으면 x가 y쪽으로 붙음
        parent[x] = y;
        sz[y] += sz[x]; // y의 사이즈에 x 사이즈 더함
        ret = sz[y];
    } else { // 아니면
        parent[y] = x;
        sz[x] += sz[y]; // x 사이즈에 y 사이즈 더함
        ret = sz[x];
    }

    if(rk[x] == rk[y]) { // 랭크가 같으면 랭크가 하나 증가(이때 root는 x)
        rk[x]++;
    }

    return ret;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while(t--) {
        string s1, s2;
        int k=1;
        cin >> f;

        mp.clear();
        memset(rk, 0, sizeof(rk));
        memset(parent, 0, sizeof(parent));
        memset(sz, 0, sizeof(sz));

        for(int i=0;i<f;i++) {
            cin >> s1 >> s2;

            int n1, n2;
            if(mp[s1] == 0) { // 맵에 값이 없으면
                n1 = k++;
                parent[n1] = n1; // 이 노드의 부모는 자기 자신
                rk[n1] = 0; // 차수 0
                sz[n1] = 1; // 사이즈 1
                mp[s1] = n1; // 맵에 할당
            } else {
                n1 = mp[s1];
            }

            if(mp[s2] == 0) { // 맵에 값이 없으면
                n2 = k++;
                parent[n2] = n2; // 이 노드의 부모는 자기 자신
                rk[n2] = 0; // 차수 0
                sz[n2] = 1; // 사이즈 1
                mp[s2] = n2; // 맵에 할당
            } else {
                n2 = mp[s2];
            }

            cout << merge(n1, n2) << "\n"; // n1, n2 합친 사이즈 출력

        }
    }

    return 0;
}