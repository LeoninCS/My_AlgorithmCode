/*
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<int> vis(n * m, 0);
        vector<int> dis(n * m, 1e9 + 1e8);
        vector<int> cnt(n * m, 0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,0});
        dis[0] = 0;
        cnt[0] = 1;
        while(!pq.empty()) {
            auto pa = pq.top();
            pq.pop();
            int d = pa.first;
            int u = pa.second;
            if(u == n * m - 1) break;
            if(vis[u]) continue;
            vis[u] = 1;
            int add = (cnt[u] % 2 == 1) ? 1 : 2;
            if(u / m > 0 && !vis[u - m] && max(d ,moveTime[u / m - 1][u % m]) + add < dis[u - m]) {
                cnt[u - m] = cnt[u] + 1;
                dis[u - m] = max(d ,moveTime[u / m - 1][u % m]) + add;
                pq.push({dis[u - m], u - m});
                
            } 
            if(u / m < n - 1 && !vis[u + m] && max(d ,moveTime[u / m + 1][u % m]) + add < dis[u + m]) {
                cnt[u + m] = cnt[u] + 1;
                dis[u + m] = max(d ,moveTime[u / m + 1][u % m]) + add;
                pq.push({dis[u + m], u + m});
            } 
            if(u % m > 0 && !vis[u - 1] && max(d ,moveTime[u / m][u % m - 1]) + add < dis[u - 1]) {
                cnt[u - 1] = cnt[u] + 1;
                dis[u - 1] = max(d ,moveTime[u / m][u % m - 1]) + add;
                pq.push({dis[u - 1], u - 1});
            }
            if(u % m <  m - 1 && !vis[u + 1] && max(d ,moveTime[u / m][u % m + 1]) + add < dis[u + 1]) {
                cnt[u + 1] = cnt[u] + 1;
                dis[u + 1] = max(d ,moveTime[u / m][u % m + 1]) + add;
                pq.push({dis[u + 1], u + 1});
            }
        }
        return dis[n * m - 1];
    }
};
*/