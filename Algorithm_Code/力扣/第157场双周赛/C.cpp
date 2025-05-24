/*
//bfs（层序遍历）+数学推理
class Solution {
public:
    long long mod = 1e9 + 7;
    long long qmi(long long a, long long b) {
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
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> floor(n + 1, 0);
        vector<vector<int>> v(n + 1);
        for(int i = 0; i < n - 1; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
        }
        queue<int> q;
        q.push(1);
        int cnt = -1;
        while(!q.empty()) {
            int k = q.size();
            for(int i = 0; i < k; i++) {
                int tp = q.front();
                q.pop();
                floor[tp] = cnt;
                for(auto &son: v[tp]) q.push(son);
            }
            cnt++;
        } 
        long long ans = qmi(2,cnt - 1);
        return ans;
    }
};
*/