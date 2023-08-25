class Solution {
public:
int myAtoi(string s) {
	string h = "";
	int idx = 0;
	long long result;
	while (idx < s.size() && s[idx] == ' ') idx++;
	while (idx < s.size() && (s[idx] == '-' || s[idx] == '+')) {
		h += s[idx];
		idx++;
	}
	if ((h != "-" && h != "+") && h != "") return 0;
	while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9') {
		h += s[idx];
		result = std::stoll(h);
		if (result > INT_MAX) return INT_MAX;
		if (result < INT_MIN) return INT_MIN;
		idx++;
	}
	if (h == "" || h == "-" || h == "+")return 0;
		else return (int)result;
}
};