/*
链表变形
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> vis1(n, -1);
        vector<int> dis1(n, -1);
        int cnt = 0;
        while(true) {
            if(node1 == -1 || vis1[node1] == 1) break;
            vis1[node1] = 1;
            dis1[node1] = cnt;
            cnt++;
            node1 = edges[node1];
        }
        vector<int> vis2(n, -1);
        vector<int> dis2(n, -1);
        cnt = 0;
        while(true) {
            if(node2 == -1 || vis2[node2] == 1) break;
            vis2[node2] = 1;
            dis2[node2] = cnt;
            cnt++;
            node2 = edges[node2];
        }
        int ans = -1;
        int mi = 1e9;
        for(int i = 0; i < n; i++) {
            if(dis1[i] == -1 || dis2[i] == -1) continue;
            if(max(dis1[i],dis2[i]) < mi) {
                ans = i;
                mi = max(dis1[i],dis2[i]);
            }
        }
        return ans;
    }
};
*/