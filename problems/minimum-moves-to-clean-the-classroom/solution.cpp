class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sx = -1, sy = -1, cnt = 0;
        vector<vector<int>> litterIdx(m, vector<int>(n, -1));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (classroom[i][j] == 'L') {
                    litterIdx[i][j] = cnt++;
                }
            }
        }
        if (cnt == 0)
            return 0;

        int full = (1 << cnt) - 1;

        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                   n, vector<vector<bool>>(energy + 1,
                                           vector<bool>(1 << cnt, false))));

        queue<tuple<int, int, int, int>> q;
        q.push({sx, sy, energy, 0});
        visited[sx][sy][energy][0] = true;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int k = 0; k < sz; ++k) {
                auto [x, y, e, mask] = q.front();
                q.pop();

                if (mask == full)
                    return steps;
                if (e <= 0)
                    continue; // no energy left, dead end from here

                for (int d = 0; d < 4; ++d) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (classroom[nx][ny] == 'X')
                        continue;

                    int ne = (classroom[nx][ny] == 'R') ? energy : e - 1;
                    int nmask = mask;
                    if (litterIdx[nx][ny] != -1)
                        nmask |= (1 << litterIdx[nx][ny]);

                    if (!visited[nx][ny][ne][nmask]) {
                        visited[nx][ny][ne][nmask] = true;
                        q.push({nx, ny, ne, nmask});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};