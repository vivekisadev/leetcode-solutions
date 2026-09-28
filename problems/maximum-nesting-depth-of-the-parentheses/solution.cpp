class Solution {
public:
    int maxDepth(string s) {
        int currD = 0;
        int maxD = 0;

        for(char c : s){
            if(c == '('){
                currD++;
                maxD = max(maxD, currD);
            } else if(c == ')'){
                currD--;
            }
        }

        return maxD;
    }
};