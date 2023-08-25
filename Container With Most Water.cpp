class Solution {
public:
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1, max_area = 0, area;
    while (left < right) {
        area = std::min(height[left], height[right]) * (right - left);
        max_area = max(area, max_area);
        if (height[left] >= height[right]) right--;
        else left++;
    }
    return max_area;
}
};