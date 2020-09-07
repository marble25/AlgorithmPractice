//
// Created by marble on 20. 9. 7..
//

// 조건이 꽤 까다로운 문제
// BFS로 풀 거라고는 상상도 못하다가 안풀려서 여러 질문들을 참고해서 푼 문제

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

string n;
int k;
int visited[1000005] = {0};
queue<pair<int, string>> q;

int ans = -1;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    cin >> k;

    q.push({1, n});
    visited[stoi(n)] = 1;

    int sz = n.length();

    while(!q.empty()) { // BFS 이용
        int dis = q.front().first; // 거리
        string s = q.front().second;
        int org_num = stoi(s);
        q.pop();

        if(dis > k+1) break; // 거리가 k+2부터는 필요 없음
        if(dis == k+1) ans = max(ans, org_num); // 거리가 k+1인 경우 ans 업데이트

        for(int i=0;i<sz-1;i++) {
            for(int j=i+1;j<sz;j++) {
                if(i == 0 && s[j] == '0') continue; // 앞자리에 0이 들어갈 수 없음

                swap(s[i], s[j]); // i와 j를 바꿈
                int num = stoi(s);

                if(visited[num] != dis + 1) { // 같은 단계를 추가하지 않도록 설정
                    q.push({dis+1, s});
                    visited[num] = dis + 1;
                }

                swap(s[i], s[j]); // 원상복구
            }
        }
    }

    cout << ans;
    return 0;
}