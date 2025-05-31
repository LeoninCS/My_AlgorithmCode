/*
//dfs变形
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        int m = edges2.size();
        vector<vector<int>> graph1(n+1);
        for(auto edge : edges1) {
            int x = edge[0],y = edge[1];
            graph1[x].push_back(y);
            graph1[y].push_back(x);
        }
        vector<vector<int>> graph2(m+1);
        for(auto edge : edges2) {
            int x = edge[0],y = edge[1];
            graph2[x].push_back(y);
            graph2[y].push_back(x);
        }
        vector<int> vis1(n+1,0);
        vector<int> vis2(m+1,0);
        function<int(int,int)> dfs1 = [&](int root,int d) -> int {
            if(d > k) {
                return 0;
            }
            vis1[root] = 1;
            int best = 1;
            for(int a:graph1[root]) {
                if(!vis1[a]) {
                    best += dfs1(a,d+1);
                }
            }
            return best;
        };
        function<int(int,int)> dfs2 = [&](int root,int d) -> int {
            if(d > k) {
                return 0;
            }
            vis2[root] = 1;
            int best = 1;
            for(int a:graph2[root]) {
                if(!vis2[a]) {
                    best += dfs2(a,d+1);
                }
            }
            return best;
        };
        int best2 = 0;
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= m; j++) vis2[j] = 0;
            best2 = max(best2,dfs2(i,1));
        }
        vector<int> ans;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) vis1[j] = 0;
            ans.push_back(dfs1(i,0) + best2);
        }   
        cout << best2;
        return ans;
    }
};
*/