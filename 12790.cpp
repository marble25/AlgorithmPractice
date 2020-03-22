//
// Created by marble on 20. 3. 22..
//

#include <iostream>
using namespace std;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) {
        int hp, mp, atk, def;
        int d_hp, d_mp, d_atk, d_def;
        int result;
        cin >> hp >> mp >> atk >> def;
        cin >> d_hp >> d_mp >> d_atk >> d_def;
        hp += d_hp;
        mp += d_mp;
        atk += d_atk;
        def += d_def;

        hp = (hp <= 1? 1 : hp);
        mp = (mp <= 1? 1 : mp);
        atk = (atk <= 0 ? 0 : atk);
        result = hp + 5 * mp + 2 * atk + 2 * def;
        cout << result << endl;
    }
    return 0;
}