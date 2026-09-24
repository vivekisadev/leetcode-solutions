class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> result(n1 + n2, 0);

        for (int i = n1 - 1; i >= 0; i--) {
            int d1 = num1[i] - '0';
            for (int j = n2 - 1; j >= 0; j--) {
                int d2 = num2[j] - '0';
                int mul = d1 * d2;
                int p1 = i + j;      // position for carry
                int p2 = i + j + 1;  // position for current digit

                int sum = mul + result[p2];

                result[p2] = sum % 10;
                result[p1] += sum / 10;
            }
        }

        string res = "";
        for (int digit : result) {
            if (!(res.empty() && digit == 0)) {
                res += to_string(digit);
            }
        }

        return res.empty() ? "0" : res;
    }
};