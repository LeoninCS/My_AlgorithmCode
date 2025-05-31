/*
//层序遍历变形
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        vector<vector<int>> son1(n);
        vector<int> floor1(n, -1);
        for(int i = 0; i < n - 1; i++) {
            int u = edges1[i][0];
            int v = edges1[i][1];
            son1[u].push_back(v);
            son1[v].push_back(u);
        }
        queue<int> q1;
        q1.push(0);
        int cnt1 = 0;
        int cnt11 = 0, cnt12 = 0;
        while(!q1.empty()) {
            int k = q1.size();
            for(int i = 0; i < k; i++) {
                int u = q1.front();
                q1.pop();
                floor1[u] = cnt1;
                if(cnt1 % 2 == 0) cnt12++;
                else cnt11++;
                for(auto v:son1[u]) {
                    if(floor1[v] == -1) {
                        q1.push(v);
                    }
                }
            }
            cnt1++;
        }

        int m = edges2.size() + 1;
        vector<vector<int>> son2(m);
        vector<int> floor2(m, -1);
        for(int i = 0; i < m - 1; i++) {
            int u = edges2[i][0];
            int v = edges2[i][1];
            son2[u].push_back(v);
            son2[v].push_back(u);
        }
        queue<int> q2;
        q2.push(0);
        int cnt2 = 0;
        int cnt21 = 0, cnt22 = 0;
        while(!q2.empty()) {
            int k = q2.size();
            for(int i = 0; i < k; i++) {
                int u = q2.front();
                q2.pop();
                floor2[u] = cnt2;
                //cout << cnt2;
                if(cnt2 % 2 == 0) cnt22++;
                else cnt21++;
                for(auto v:son2[u]) {
                    if(floor2[v] == -1) {
                        q2.push(v);
                    }
                }
            }
            cnt2++;
        }
        int mx = max(cnt21,cnt22);
        //cout << mx;
        vector<int> ans;
    for(int i = 0; i < n; i++) {
        //cout << floor1[i] << " ";
        if(floor1[i] % 2 == 0) ans.push_back(cnt12 + mx);
        else ans.push_back(cnt11 + mx);
    }
    return ans;
    }
};
*/