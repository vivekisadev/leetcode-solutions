class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask; 

        for (auto& res : reservedSeats) {
            int row = res[0], seat = res[1];
            if (seat >= 2 && seat <= 9) {
                rowMask[row] |= (1 << (seat - 2));
            }
        }

        const int leftMask   = 0b00001111;
        const int middleMask = 0b00111100;
        const int rightMask  = 0b11110000;

        long long total = 2LL * (n - rowMask.size());

        for (auto& [row, mask] : rowMask) {
            bool leftFree   = (mask & leftMask) == 0;
            bool rightFree  = (mask & rightMask) == 0;
            bool middleFree = (mask & middleMask) == 0;

            if (leftFree && rightFree) {
                total += 2;
            } else if (leftFree || rightFree || middleFree) {
                total += 1;
            }
        }

        return (int)total;
    }
};