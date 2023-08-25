class Solution {
private:
    struct PairOfThree {
        int open;
        int close;
        string str;
        PairOfThree(int a, int b, string c) : open(a), close(b), str(c) {};
    };
public:
    vector<string> generateParenthesis(int n) {
        vector <string>result;
        stack <PairOfThree>stk;

        stk.push(PairOfThree(0,0,""));
        while (!stk.empty()) {
            PairOfThree curr = stk.top();
            stk.pop();
            if (curr.open == n && curr.close == n) {
                result.push_back(curr.str);
            }

            if (curr.open < n) {
                stk.push(PairOfThree(curr.open + 1, curr.close, curr.str + "("));
            }

            if (curr.open > curr.close) {
                stk.push(PairOfThree(curr.open, curr.close + 1, curr.str + ")"));
            }
        }
        return result;
    }
};