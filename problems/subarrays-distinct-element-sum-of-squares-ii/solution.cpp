class Solution {
    typedef long long ll;
    vector<ll> sum, sq, lz;

    void apply(int node, int len, ll x) {
        sq[node] += 2 * x * sum[node] + x * x * len;  // (s + x)^2 summed over the range
        sum[node] += x * len;
        lz[node] += x;
    }

    void push(int node, int l, int r) {
        if (lz[node] == 0) return;
        int m = (l + r) / 2;
        apply(2 * node, m - l + 1, lz[node]);
        apply(2 * node + 1, r - m, lz[node]);
        lz[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(node, r - l + 1, 1);
            return;
        }
        push(node, l, r);
        int m = (l + r) / 2;
        update(2 * node, l, m, ql, qr);
        update(2 * node + 1, m + 1, r, ql, qr);
        sum[node] = sum[2 * node] + sum[2 * node + 1];
        sq[node] = sq[2 * node] + sq[2 * node + 1];
    }

public:
    int sumCounts(vector<int>& nums) {
        const ll MOD = 1e9 + 7;
        int n = nums.size();
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lz.assign(4 * n, 0);

        vector<int> last(100001, -1);
        ll res = 0;

        for (int j = 0; j < n; j++) {
            // every left end in (last[nums[j]], j] gains one new distinct value
            update(1, 0, n - 1, last[nums[j]] + 1, j);
            last[nums[j]] = j;

            // positions > j are still 0, so the root holds sum of f(i)^2 for i <= j
            res = (res + sq[1]) % MOD;
        }
        return (int)res;
    }
};