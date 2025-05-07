/*
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<int> vis(n * m, 0);
        vector<int> dis(n * m, 1e9 + 1e8);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,0});
        dis[0] = 0;
        while(!pq.empty()) {
            auto pa = pq.top();
            pq.pop();
            int d = pa.first;
            int u = pa.second;
            if(vis[u]) break;
            vis[u] = 1;
            if(u / m > 0 && !vis[u - m] && max(d ,moveTime[u / m - 1][u % m]) + 1 < dis[u - m]) {
                dis[u - m] = max(d ,moveTime[u / m - 1][u % m]) + 1;
                pq.push({dis[u - m], u - m});
            } 
            if(u / m < n - 1 && !vis[u + m] && max(d ,moveTime[u / m + 1][u % m]) + 1 < dis[u + m]) {
                dis[u + m] = max(d ,moveTime[u / m + 1][u % m]) + 1;
                pq.push({dis[u + m], u + m});
            } 
            if(u % m > 0 && !vis[u - 1] && max(d ,moveTime[u / m][u % m - 1]) + 1 < dis[u - 1]) {
                dis[u - 1] = max(d ,moveTime[u / m][u % m - 1]) + 1;
                pq.push({dis[u - 1], u - 1});
            }
            if(u % m <  m - 1 && !vis[u + 1] && max(d ,moveTime[u / m][u % m + 1]) + 1 < dis[u + 1]) {
                dis[u + 1] = max(d ,moveTime[u / m][u % m + 1]) + 1;
                pq.push({dis[u + 1], u + 1});
            }
        }
        return dis[n * m - 1];
    }
};
*/