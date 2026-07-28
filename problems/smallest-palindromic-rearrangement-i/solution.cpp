class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        string firsthalf = s.substr(0,n/2);
        sort(firsthalf.begin(), firsthalf.end());

        string result = firsthalf;
        if( n%2 == 1 ){
            result += s[n/2];
        }

        reverse(firsthalf.begin(), firsthalf.end());
        result += firsthalf;

        return result;
    }
};