class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> ones1, ones2;


        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j] == 1) ones1.push_back({i, j});
                if(img2[i][j] == 1) ones2.push_back({i, j});
            }
        }

        unordered_map<int, int> count;
        int best = 0;

        for(auto& a : ones1){
            for(auto& b : ones2){
                int dx = b.first - a.first;
                int dy = b.second - a.second;
                int key  = (dx + n) * (2 * n) + (dy + n);
                count[key]++;
                best = max(best, count[key]);
            }
        }

        return best;
    }
};