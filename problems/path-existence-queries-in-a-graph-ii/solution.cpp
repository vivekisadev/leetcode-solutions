class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return nums[a] < nums[b]; });

        vector<int> pos(n), vals(n);
        for (int i = 0; i < n; i++) {
            pos[idx[i]] = i;
            vals[i] = nums[idx[i]];
        }

        // right[i]: farthest position reachable in ONE hop from position i
        vector<int> right(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            r = max(r, i);
            while (r + 1 < n && vals[r + 1] - vals[i] <= maxDiff) r++;
            right[i] = r;
        }

        // Connected components via running max
        vector<int> comp(n);
        int compId = 0, runningMax = 0;
        for (int i = 0; i < n; i++) {
            comp[i] = compId;
            runningMax = max(runningMax, right[i]);
            if (runningMax <= i && i + 1 < n) compId++;
        }

        // Binary lifting table
        int LOG = max(1, (int)ceil(log2(max(2, n))));
        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = right;
        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++)
                up[k][i] = up[k - 1][up[k - 1][i]];

        auto minSteps = [&](int u, int v) -> int {
            if (u == v) return 0;
            if (u > v) swap(u, v);
            if (right[u] >= v) return 1;
            int cur = u, steps = 0;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < v) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }
            return steps + 1; // one more hop needed to cover v
        };

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int pu = pos[q[0]], pv = pos[q[1]];
            if (comp[pu] != comp[pv]) ans.push_back(-1);
            else ans.push_back(minSteps(pu, pv));
        }
        return ans;
    }
};