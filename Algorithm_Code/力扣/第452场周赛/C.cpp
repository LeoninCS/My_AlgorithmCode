/*

//bfs
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sx = -1, sy = -1;
        vector<pair<int, int>> leaves;
        unordered_map<int, int> leafIndex;

        // 找到起点和所有 L
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (classroom[i][j] == 'L') {
                    int idx = leaves.size();
                    leaves.emplace_back(i, j);
                    leafIndex[i * n + j] = idx;
                }
            }

        if (leaves.empty()) return 0;
        int allCollected = (1 << leaves.size()) - 1;
        int ans = INT_MAX;

        vector<vector<vector<vector<bool>>>> visited(m,
            vector<vector<vector<bool>>>(n,
                vector<vector<bool>>(energy + 1,
                    vector<bool>(1 << leaves.size(), false))));

        // DFS 函数
        function<void(int, int, int, int, int)> dfs = [&](int x, int y, int e, int mask, int steps) {
            if (x < 0 || x >= m || y < 0 || y >= n || classroom[x][y] == 'X' || e < 0) return;
            if (visited[x][y][e][mask]) return;
            visited[x][y][e][mask] = true;

            // 采集叶子
            if (classroom[x][y] == 'L') {
                int idx = leafIndex[x * n + y];
                mask |= (1 << idx);
                if (mask == allCollected) {
                    ans = min(ans, steps);
                    return;
                }
            }

            // 补充能量
            if (classroom[x][y] == 'R') e = energy;

            int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                dfs(nx, ny, e - 1, mask, steps + 1);
            }
        };

        dfs(sx, sy, energy, 0, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};


*/