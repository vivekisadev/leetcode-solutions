class Solution {
public:
    vector<int> parent, rank_;

    // Iterative find with path compression (no recursion -> no stack overflow)
    int find(int x) {
        int root = x;
        while (parent[root] != root) root = parent[root];
        // path compression pass
        while (parent[x] != root) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }
        return root;
    }

    // Union by rank/size, keeps tree shallow -> find stays near O(1)
    void unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (rank_[pu] < rank_[pv]) swap(pu, pv);
        parent[pv] = pu;
        if (rank_[pu] == rank_[pv]) rank_[pu]++;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n + 1);
        rank_.assign(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;

        for (auto& r : roads) unite(r[0], r[1]);

        int root = find(1);
        int ans = INT_MAX;
        for (auto& r : roads) {
            if (find(r[0]) == root) {
                ans = min(ans, r[2]);
            }
        }
        return ans;
    }
};