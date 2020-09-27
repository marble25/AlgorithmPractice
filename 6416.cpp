//
// Created by marble on 20. 9. 27..
//

// 트리인지 판별하는 간단한 문제
// 그래도 생각할 조건이 많아서 여러 가지 경우의 수를 다 따져보았던 문제

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



int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x, y;
    int cnt = 1;
    while(true) {
        bool is_empty = true; // 빈 그래프이면 무조건 트리
        bool is_tree = true;

        vector<int> linked[105];
        int parent[105] = {0};

        while(true) {
            cin >> x >> y;
            if(x < 0 && y < 0) return 0;
            if(x == 0 && y == 0) break;

            is_empty = false; // 하나라도 있으면 빈 그래프가 아님
            linked[x].push_back(y);

            if(parent[y] != 0) { // 부모가 하나 이상 있으면 트리가 아님
                is_tree = false;
            }
            parent[y] = x;
        }

        int root = 0;
        int root_cnt = 0;
        for(int i=1;i<=100;i++) {
            if(linked[i].size() != 0 && parent[i] == 0) { // 루트가 하나 이상 있으면 트리가 아님
                root_cnt++;
                root = i;
            }
        }

        if(root_cnt != 1) {
            is_tree = false;
        } else { // 사이클이 존재하면 트리가 아님
            for(int i=1;i<=100;i++) {
                if(parent[i] != 0) {
                    int x = parent[i];
                    while(x != root) {
                        if(x == i) {
                            is_tree = false;
                            break;
                        }
                        x = parent[x];
                    }

                    if(!is_tree) {
                        break;
                    }
                }
            }
        }


        if(is_empty || is_tree) {
            cout << "Case " << cnt << " is a tree.\n";
        } else {
            cout << "Case " << cnt << " is not a tree.\n";
        }

        cnt++;
    }
    return 0;
}