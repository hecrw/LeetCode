class Solution {
public:
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counter;
    vector<vector<int>>bucket(nums.size() + 1);
    vector <int> res;
    for (int i : nums) {
        if (counter.count(i) > 0) {
            counter[i] += 1;
        }
        else {
            counter.insert({ i, 1 });
        }
    }
    for (const auto& pair : counter) {
        bucket[pair.second].push_back(pair.first);
    }
    for (int i = nums.size();i >= 0;i--) {
        if (res.size() >= k) break;

        if (!bucket[i].empty()) {
            res.insert(res.end(), bucket[i].begin(), bucket[i].end());
        }
    }
    return res;
}
};