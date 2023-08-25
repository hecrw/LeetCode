class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        unordered_map<char, int> anagram;
        for (char c : s1) {
            if (anagram.count(c) > 0) {
                anagram[c]++;
            }
            else {
                anagram.insert({ c,1 });
            }
        }
        int count = s1.size(), left = 0;
        for (int right = 0; right < s2.size();right++) {
            char rc = s2[right];
            if (anagram.count(rc) > 0) {
                anagram[rc]--;
                if (anagram[rc] >= 0) {
                    count--;
                }
            }


            if (right - left + 1 == s1.size()) {
                if (count == 0) return true;

                char lc = s2[left];
                if (anagram.count(lc) > 0) {
                    anagram[lc]++;
                    if (anagram[lc] > 0) count++;
                }
                left++;
            }

        }
        return false;
    }
};