class Solution {
public:
int evalRPN(vector<string>& tokens) {
    int  res = 0, top = 0;
    for (string s : tokens) {
        if (std::isdigit(s[0]) || s.size() > 1) {
            top = res;
            res = stoi(s);
            continue;
        }
        int num1 = res;
        res = top;
        int num2 = top;
        if (s == "-") res = num2 - num1;

        else if (s == "+") res = num2 + num1;

        else if (s == "*") res = num2 * num1;

        else res = num2 / num1;
    }
    return res;
}
};