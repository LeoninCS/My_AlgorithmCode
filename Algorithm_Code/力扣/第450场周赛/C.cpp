/*
//bfs变式
class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<pair<int,int>>> az(26);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] != '.' && matrix[i][j] != '#') {
                    int idx = matrix[i][j] - 'A';
                    az[idx].push_back({i,j});
                }
            }
        }
        vector<vector<int>> dis(m,vector<int>(n, -1));
        int movex[4] = {0,0,1,-1};
        int movey[4] = {1,-1,0,0};
        queue<pair<int,int>> q;
        if(matrix[0][0] != '.' && matrix[0][0] != '#') {
            int idx = matrix[0][0] - 'A';
            for(int z = 0; z < az[idx].size(); z++) {
                dis[az[idx][z].first][az[idx][z].second] = 0;    
                q.push({az[idx][z].first,az[idx][z].second});
            }
        } else {
            q.push({0,0});
            dis[0][0] = 0;
        }
        while(q.size()) {
            int k = q.size();
            for(int i = 0; i < k; i++) {
                auto[y,x] = q.front();
                q.pop();
                for(int j = 0; j < 4; j++) {
                    int ny = y + movey[j];
                    int nx = x + movex[j];
                    if(ny >= 0 && ny < m && nx >= 0 && nx < n && dis[ny][nx] == -1 && matrix[ny][nx] != '#') {
                        if(matrix[ny][nx] != '.') {
                            int idx = matrix[ny][nx] - 'A';
                            for(int z = 0; z < az[idx].size(); z++) {
                                dis[az[idx][z].first][az[idx][z].second] = dis[y][x] + 1;    
                                q.push({az[idx][z].first,az[idx][z].second});
                            }
                        } else {
                            dis[ny][nx] = dis[y][x] + 1;
                            q.push({ny,nx});
                        }
                    }
                }
            }
        }
        return dis[m - 1][n - 1];
    }
};
*/