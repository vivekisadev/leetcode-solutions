class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<vector<int>> adj(n);
        for (auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }

        vector<bool> bad(n, false);
        bad[k] = true;
        queue<int> q;
        q.push(k);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int nxt : adj[curr]) {
                if (!bad[nxt]) {
                    bad[nxt] = true;
                    q.push(nxt);
                }
            }
        }

        for (auto& inv : invocations) {
            if (!bad[inv[0]] && bad[inv[1]]) {
                // not safe to delete anything
                vector<int> all;
                all.reserve(n);
                for (int i = 0; i < n; i++)
                    all.push_back(i);
                return all;
            }
        }

        vector<int> result;
        result.reserve(n);
        for (int i = 0; i < n; i++) {
            if (!bad[i])
                result.push_back(i);
        }

        return result;
    }
};