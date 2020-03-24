//
// Created by marble on 20. 3. 24..
//

// 이 것은 생각해내기 쉽지 않았다.
// 생각해 내기만 한다면 맞출 만한 문제였는데..

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

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    char s[500005];
    deque<char> dq;
    cin >> n >> k;
    cin >> s;

    for(int i=0;i<n;i++) {
        while(k != 0 && !dq.empty() && dq.back() < s[i]) { // deq에 들어간 수 중 s[i]보다 작은 수는 빼버린다. -> 내림차순으로 정렬된다.
            dq.pop_back();
            k--;
        }
        dq.push_back(s[i]);
    }
    for(int i=0;i<dq.size() - k;i++) { // s[i]보다 작은 수는 모두 빼버린 후에도 k가 남아있으면 뒤에서 뺀다.(뒤의 수가 작으므로)
        cout << dq[i];
    }
    return 0;
}