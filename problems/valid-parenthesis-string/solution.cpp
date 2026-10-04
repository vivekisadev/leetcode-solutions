class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        unordered_map<char, int> count;
        for(char c : s){
            count[c]++;
        }
        if(count['('] == count[')']) return true;
        else if(abs(count['('] - count[')']) == 1 && count['*'] == 1) return true;
        else return false;
        
    }
};