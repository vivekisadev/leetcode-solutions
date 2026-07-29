class Solution {
    long long perms(vector<int>& cnt, int len, long long cap) {
        long long res = 1;
        int rem = 0;
        for (int c = 0; c < 26; c++) {
            for (int i = 1; i <= cnt[c]; i++) {
                rem++;
                __int128 tmp = (__int128)res * rem / i;
                res = (tmp > cap) ? cap : (long long)tmp;
                if (res >= cap) return cap;
            }
        }
        return res;
    }
public:
    string smallestPalindrome(string s, long long k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int mid = -1, halfLen = 0;
        vector<int> half(26, 0);
        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1) mid = i;
            half[i] = freq[i] / 2;
            halfLen += half[i];
        }

        const long long CAP = 2e18;
        if (perms(half, halfLen, CAP) < k) return "";

        string first;
        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (!half[c]) continue;
                half[c]--;
                long long cnt = perms(half, halfLen - pos - 1, CAP);
                if (cnt >= k) { first += ('a' + c); break; }
                k -= cnt;
                half[c]++;
            }
        }

        string ans = first;
        if (mid != -1) ans += char('a' + mid);
        ans += string(first.rbegin(), first.rend());
        return ans;
    }
};