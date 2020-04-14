// 조금 더 생각하면 풀 수 있었을 것 같기도 한데
// 잘 안풀려서 해답을 보고 푼 문제
// 스택이 변형되니 꽤 어려움을 느꼈다.

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

int n, height;
stack<pair<int, int>> st; // 키, 앞쪽 방향으로 연속으로 만날 수 있는 사람 수

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    long long result = 0;
    for(int i=0;i<n;i++) {
        cin >> height;
        while(!st.empty() && st.top().first < height) { // 현재 값보다 더 작은 사람들은 어차피 뒷 사람이랑 연결될 수 없다. 따라서 제거해버린다.
            result += st.top().second;
            st.pop();
        }

        if(st.empty()) { // 스택이 비어있으면 push
            st.push(make_pair(height, 1));
        } else {
            if(st.top().first == height) { // 가장 큰 사람의 키가 현재 사람의 키와 같다면
                pair<int, int> cur = st.top();
                st.pop();

                result += cur.second;
                if(!st.empty()) { // 키가 더 큰 사람이 남아 있다면 result에 더해줌
                    result ++;
                }

                // 뒷 사람과 연결된 것을 고려해서 하나 증가된 값을 넣음
                cur.second++;
                st.push(cur);
            } else {
                st.push(make_pair(height, 1)); // 스택 내에 가장 큰 사람과 현재 사람이 쌍을 이룸
                result ++;
            }
        }

    }
    cout << result;
    return 0;
}