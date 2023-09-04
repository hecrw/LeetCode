#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>>h;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        h[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        string result = "";
        if(h.count(key) > 0){
             int left = 0, right = h[key].size() - 1;
             while(left <= right){
                int mid = (left + right) / 2;
                if(h[key][mid].second <= timestamp){
                    result = h[key][mid].first;
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
             }
        }
        return result;
    }
};