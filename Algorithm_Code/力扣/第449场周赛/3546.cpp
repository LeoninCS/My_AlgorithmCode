/*
//二维前缀和
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>> pre(n + 1,vector<long long>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int  j = 1; j <= m; j++) {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + grid[i - 1][j - 1];
                //cout << pre[i][j] << " ";
            }
            //cout << endl;
        }
        //cout << pre[1][2];
        for(int i = 1; i <= m; i++) {
            if(2 * pre[n][i] == pre[n][m]) return true;
        }
        for(int i = 1; i<= n; i++) {
            if(2 * pre[i][m] == pre[n][m]) return true;
        }
        return false;
    }
};
*/