class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int depth = 0;
        for (char c : s) {
            if (c == '(') {
                if (depth > 0) res += c;  // not an outermost '('
                depth++;
            } else {
                depth--;
                if (depth > 0) res += c;  // not an outermost ')'
            }
        }
        return res;
    }
};