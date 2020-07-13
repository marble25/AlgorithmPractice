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
int s[20][20] = {0};

int cache[1<<20] = {0};
bool visited[1<<20] = {0};

int f(int x) {
    for(int i=x+1;i<n;i++) {

    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> s[i][j];
        }
    }


    return 0;
}