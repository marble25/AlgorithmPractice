//
// Created by marble on 20. 12. 9..
//

// 기초 문제인데도 쉽지 않다.
// 전위, 중위, 후위 표현식도 다시 복습해 봐야겠다.


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

int priority(char ch) {
    if (ch == '(') return 0;
    else if (ch == '+' || ch == '-') return 1;
    else return 2;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    stack<char> s;
    string ans, ops;

    cin >> ans;

    for(char ch : ans) {
        if(ch >= 'A' && ch <= 'Z') { // 문자는 그냥 문자열에 더해줌
            ops += ch;
        } else if(ch == '(') { // 여는 괄호가 나오면 stack에 넣음
            s.push(ch);
        } else if(ch == ')') { // 닫는 괄호가 나오면 여는 괄호가 나올 때까지의 모든 연산자를 문자열에 더해줌
            while(!s.empty()) {
                if(s.top() == '(') {
                    s.pop();
                    break;
                }

                ops += s.top();
                s.pop();
            }
        } else { // 연산자가 나오면
            while(!s.empty() && priority(s.top()) >= priority(ch)) { // stack에 존재하는 모든 낮은 순위 연산자들을 문자열에 더해줌
                ops += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) { // stack에 남아 있는 연산자를 문자열에 더해줌
        ops += s.top();
        s.pop();
    }

    cout << ops << "\n";

    return 0;
}