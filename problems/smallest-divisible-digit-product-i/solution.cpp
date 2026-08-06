class Solution {
public:
    int smallestNumber(int n, int t) {
        int N = n;
        
        while(true){
            int prd = 1;
            for(int i = N;i>0;i /= 10){
                prd *= i%10;
            }
            if(prd % t == 0) break ;
            N++;
        }
        return N;
    }
};