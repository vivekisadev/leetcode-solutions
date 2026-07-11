class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(n, false);
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            vector<int> nodes;
            stack<int> st;
            st.push(i);
            visited[i] = true;
            
            while (!st.empty()) {
                int u = st.top(); st.pop();
                nodes.push_back(u);
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        st.push(v);
                    }
                }
            }
            
            long long nodeCnt = nodes.size();
            long long edgeCnt = 0;
            for (int u : nodes) edgeCnt += adj[u].size();
            edgeCnt /= 2;
            
            if (edgeCnt == nodeCnt * (nodeCnt - 1) / 2) ans++;
        }
        
        return ans;
    }
};