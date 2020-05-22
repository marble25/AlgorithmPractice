//
// Created by marble on 20. 5. 22..
//

// Stack을 이용한 간단한 문제

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

int n;
char word[100005];
int cnt = 0;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> word;

        int len = strlen(word);
        stack<int> st;

        for(int j=0;j<len;j++) {
            if(word[j] == 'A') { // A가 들어오면
                if(st.empty() || st.top() != 1) { // Stack에 A가 없다면 push
                    st.push(1);
                } else { // A가 있으면 A를 빼줌
                    st.pop();
                }

            } else if(word[j] == 'B'){ // B가 들어오면
                if(st.empty() || st.top() != 2) { // Stack에 B가 없다면 push
                    st.push(2);
                } else { // B가 있으면 B를 빼줌
                    st.pop();
                }
            }
        }

        if(st.empty()) { // Stack이 비어있으면(Stack의 쌍이 모두 맞아 떨어지면) cnt 증가
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}