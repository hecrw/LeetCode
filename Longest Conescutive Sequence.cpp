class Solution {
public:
int longestConsecutive(vector<int>& nums) {
    std::unordered_map<int, int>h;
    int max = 0, curr = 0;
    for (int i : nums) h[i] = 0;

    for (int i : nums) {
        if (h.count(i - 1) > 0)continue;
        else {
            int temp = i;
            while (h.count(temp) > 0) {
                h.erase(temp);
                curr++;
                temp++;
            }
            if (curr > max) max = curr;
            curr = 0;
        }
    }
    return max;
}
};