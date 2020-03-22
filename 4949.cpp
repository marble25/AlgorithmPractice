//
// Created by marble on 20. 3. 22..
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <string>
using namespace std;

// 스택에 넣어서 가장 최근에 들어온 괄호가 짝이 맞는지 판단해주면 됨

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true) {
        string s;
        stack<int> st;

        getline(cin, s);
        if(s.size() == 1 && s[0] == '.') {
            break;
        }
        bool is_balanced = true;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '[') {
                st.push(1);
            } else if(s[i] == ']') {
                if(st.size() == 0 || st.top() != 1) { // 스택이 비어있거나 (균현 문자열에서 ]가 갑자기 들어옴) 앞 괄호가 [가 아닐 때
                    is_balanced = false;
                    break;
                } else {
                    st.pop();
                }
            } else if(s[i] == '(') {
                st.push(2);
            } else if(s[i] == ')') {
                if(st.size() == 0 || st.top() != 2) { // 스택이 비어있거나 (균현 문자열에서 )가 갑자기 들어옴) 앞 괄호가 (가 아닐 때
                    is_balanced = false;
                    break;
                } else {
                    st.pop();
                }
            }
        }
        if(st.size() != 0) { // 남아 있는 (나 [가 있을 때
            is_balanced = false;
        }
        if(is_balanced) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }
    return 0;
}