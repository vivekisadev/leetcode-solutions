class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        backtrack(cur, ans, 0, 0, n);
        return ans;
    }

private:
    void backtrack(string& cur, vector<string>& ans, int open, int close, int n) {
        if (cur.size() == 2 * n) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(cur, ans, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(cur, ans, open, close + 1, n);
            cur.pop_back();
        }
    }
};