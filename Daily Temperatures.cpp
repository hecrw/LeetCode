class Solution {
public:
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector <int>result(temperatures.size());
    stack<pair<int,int>>h;
    h.push({temperatures[0], 0});
    for (int i = 1;i < temperatures.size();i++) {
        int curr = temperatures[i];
        while (!h.empty() && curr > h.top().first) {
            int temp = h.top().second;
            h.pop();
            result[temp] = i - temp;
        }
        h.push({ temperatures[i], i });
    }
    return result;
}
};