/*
//模拟
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans;
        for(int i = 0; i <= m - k; i++) {
            vector<int> v;
            for(int j = 0; j <= n - k; j++) {
                vector<int> c;
                for(int a = i; a < i + k; a++) {
                    for(int b = j; b < j + k; b++) {
                        c.push_back(grid[a][b]);
                    }
                }
                //for(int zz = 0; zz < c.size(); zz++) cout << c[zz] << " ";
                //cout << endl;
                sort(c.begin(),c.end());
                int mi = 1e9;
                for(int z = 1; z < c.size(); z++) {
                    if(c[z] == c[z - 1]) continue;
                    mi = min(mi, c[z] - c[z - 1]);
                }
                if(mi == 1e9) mi = 0;
                v.push_back(mi);
            }
            ans.emplace_back(v);
        }
        return ans;
    }
    
};
*/