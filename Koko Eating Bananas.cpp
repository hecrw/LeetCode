class Solution {
public:
int minEatingSpeed(std::vector<int>& piles, int h) {
	int left = 1, right = 0;

	for (int i = 0;i < piles.size();i++) {
		right = std::max(right, piles[i]);
	}
	int result = right;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		long int hours = 0;

		for (int i = 0;i < piles.size();i++) {
			hours += ceil((double)piles[i] / mid);
		}

		if (hours <= h) {
			result = std::min(result, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return result;
}
};