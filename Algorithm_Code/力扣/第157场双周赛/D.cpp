/*
//bfs（层序遍历）+数学推理+LCA
class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> floor;
    vector<int> parent;
    
    long long qmi(long long a, long long b) {
        if(b < 0) return 0;
        long long res = 1;
        while (b) {
            if (b % 2 == 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b /= 2;
        }
        return res % mod;
    }
    
    // 找到最近公共祖先
    int fi(int a, int b) {
        if (floor[a] < floor[b]) swap(a, b);
        while (floor[a] > floor[b]) {
            a = parent[a];
        }
        while (a != b) {
            a = parent[a];
            b = parent[b];
        }
        return a;
    }
    
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        floor.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        vector<vector<int>> v(n + 1);
        
        for(int i = 0; i < n - 1; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
            parent[b] = a;
        }
        
        queue<int> q;
        q.push(1);
        parent[1] = -1;
        int cnt = 0;
        while(!q.empty()) {
            int k = q.size();
            for(int i = 0; i < k; i++) {
                int tp = q.front();
                q.pop();
                floor[tp] = cnt;
                for(auto &son: v[tp]) {
                    q.push(son);
                }
            }
            cnt++;
        }
        
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            int c = fi(a, b);
            int dif = floor[a] + floor[b] - 2 * floor[c];
            int add = qmi(2, dif - 1);
            ans.push_back(add);
        }
        return ans;
    }
};
*/