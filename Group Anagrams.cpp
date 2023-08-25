class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> ans;

    for (const string& s : strs) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        string key;
        for (int num : count) {
            key += to_string(num) + "#";
        }
        ans[key].push_back(s);
    }

    vector<vector<string>> res;
    for (const auto& pair : ans) {
        res.push_back(pair.second);
    }

    return res;
}

};