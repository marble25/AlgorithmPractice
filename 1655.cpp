//
// Created by marble on 20. 3. 22..
//

// priority queue를 응용한 문제
// 현재 값보다 작은값, 큰값으로 queue를 2개 만들어서 넣고 빼고 하면서 푸는 문제
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    priority_queue<int, vector<int>, less<int>> small; // 현재 값보다 작은 값들을 저장하는 pq
    priority_queue<int, vector<int>, greater<int>> big; // 현재 값보다 큰 값들을 저장하는 pq
    int n, x, current;
    cin >> n;
    cin >> x;
    cout << x << '\n';
    current = x; // 현재 값을 처음 입력받은 값으로 함
    for(int i=1;i<n;i++) {
        cin >> x;
        if(x >= current) { // 더 크거나 같은 값이 들어오면 big에 넣음
            big.push(x);
        } else { // 더 작은 값은 small에 넣음
            small.push(x);
        }
        if(big.size() - small.size() == 2) { // 큰 값 갯수 - 작은 값 갯수가 2개 차이나면 중앙값을 바꿔야 함
            small.push(current); // 현재 값을 small에 넣어주고
            current = big.top(); // current에 새 현재값(big에서 가져온 값) 대입
            big.pop();
        } else if(small.size() - big.size() == 1) { // 작은 값 갯수 - 큰 값 갯수가 1이면 중앙값을 바꿔야 함(짝수 개일 경우 더 작은 값을 말해야 하기 때문)
            big.push(current); // 현재 값을 big에 넣어주고
            current = small.top(); // current에 새 현재값(small에서 가져온 값) 대입
            small.pop();
        }
        cout << current << '\n';
    }

    return 0;
}