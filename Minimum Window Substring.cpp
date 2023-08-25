class Solution {
public:
string minWindow(string s, string t) {
    string result = "";
    if (t.size() > s.size()) return result;
    unordered_map<char, int> checker;

    for (char c : t) {
        if (checker.count(c) > 0) checker[c]++;

        else {
            checker.insert({ c, 1 });
        }
    }
    int left = 0, right = 0, count = t.size(), min_size = INT_MAX, start = 0;
    while (right < s.size()) {
        if (checker[s[right]] > 0) {
            count--;
        }
        checker[s[right]]--;
        right++;
        while (count == 0) {
            if (right - left < min_size) {
                min_size = right - left;
                start = left;
            }
            checker[s[left]]++;
            if (checker[s[left]] > 0) {
                count++;
            }
            left++;
        }
    }
    if (min_size != INT_MAX) {
        result = s.substr(start, min_size);
    }
    return result;
}
};