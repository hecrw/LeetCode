class Solution {
public:
int reverse(int x) {
    if(x == INT_MAX || x == INT_MIN) return 0;
    bool negative = false;
    if (x < 0) {
        negative = true;
        x *= -1;
    }
    stack<char>rev;
    string temp = std::to_string(x);
    for (char c : temp) rev.push(c);
    temp = "";
    while (!rev.empty()) {
        temp += rev.top();
        rev.pop();
    }
    if (std::stod(temp) >= INT_MAX || std::stod(temp) <= INT_MIN) return 0;
    else {
        if (negative) return -std::stoi(temp);
        return std::stoi(temp);
    }
}
};