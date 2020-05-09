//
// Created by marble on 20. 5. 9..
//

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

int n, k;
pair<int, int> walk[105];
pair<int, int> bike[105];
unordered_map<int, int> mp;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> walk[i].first >> walk[i].second;
        cin >> bike[i].first >> bike[i].second;
    }

    mp.insert({0, 0});
    for(int i=0;i<n;i++) {
        unordered_map<int, int> temp_map;
        for(auto &it : mp) {
            int time = it.first, cost = it.second;
            int bike_time = time + bike[i].first, bike_cost = cost + bike[i].second;
            int walk_time = time + walk[i].first, walk_cost = cost + walk[i].second;

            if(walk_time <= k) {
                auto item_walk = temp_map.find(walk_time);
                if(item_walk == temp_map.end()) {
                    temp_map[walk_time] = walk_cost;
                } else if(item_walk->second < walk_cost){
                    temp_map[walk_time] = walk_cost;
                }
            }

            if(bike_time <= k) {
                auto item_bike = temp_map.find(bike_time);
                if(item_bike == temp_map.end()) {
                    temp_map[bike_time] = bike_cost;
                } else if(item_bike->second < bike_cost) {
                    temp_map[bike_time] = bike_cost;
                }
            }

        }

        mp = temp_map;
    }

    int ans = INT32_MIN;
    for(auto &it : mp) {
        ans = max(ans, it.second);
    }

    cout << ans;


    return 0;
}