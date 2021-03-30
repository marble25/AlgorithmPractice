//
// Created by 이지호 on 21. 3. 30..
//

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
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    pair<int, int> king;
    pair<int, int> rock;
    vector<string> v = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};
    int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
    int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

    string s1, s2, input;
    int n;
    cin >> s1 >> s2 >> n;

    king.second = s1.at(0) - 'A';
    king.first = s1.at(1) - '1';

    rock.second = s2.at(0) - 'A';
    rock.first = s2.at(1) - '1';

    for(int i=0;i<n;i++) {
        cin >> input;

        for(int j=0;j<v.size();j++) {
            if(v[j] == input) {
                int mx_king = king.first + dx[j];
                int my_king = king.second + dy[j];

                if(mx_king < 0 || my_king < 0 || mx_king >= 8 || my_king >= 8) {
                    break;
                }

                if(mx_king != rock.first || my_king != rock.second) {
                    king.first = mx_king;
                    king.second = my_king;
                    break;
                }

                int mx_rock = rock.first + dx[j];
                int my_rock = rock.second + dy[j];

                if(mx_rock < 0 || my_rock < 0 || mx_rock >= 8 || my_rock >= 8) {
                    break;
                }

                king.first = mx_king;
                king.second = my_king;
                rock.first = mx_rock;
                rock.second = my_rock;
            }
        }
    }
    cout << (char)('A' + king.second) << king.first + 1 << '\n';
    cout << (char)('A' + rock.second) << rock.first + 1 << '\n';
}