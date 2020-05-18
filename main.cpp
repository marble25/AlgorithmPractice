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

char s[55];
int employee[3] = {0};

void simulate(int x) {
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;

    for(int i=0;i<strlen(s);i++) { // 직원의 출근 횟수 더해줌
        employee[s[i] - 'A'] ++;
    }

    simulate(0);

    return 0;
}