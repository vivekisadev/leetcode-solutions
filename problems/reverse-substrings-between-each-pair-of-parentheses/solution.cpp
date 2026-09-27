class Solution {
public:
    string reverseParentheses(string s) {
        while(true) {
            size_t close_idx = s.find(')');

            if(close_idx == string::npos){
                break;
            }

            size_t open_idx = s.rfind('(', close_idx);

            reverse(s.begin() + open_idx + 1, s.begin() + close_idx);

            s.erase(close_idx, 1);
            s.erase(open_idx, 1);
        }
        return s;
    }
};