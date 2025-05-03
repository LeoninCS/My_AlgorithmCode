/*
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = 1e9;
        for(int i = 1; i <= 6; i++) {
            int cnt = 0;
            bool flag = true;
            for(int j = 0; j < n; j++) {
                if(tops[j] == i) continue;
                if(bottoms[j] == i) cnt++;
                else {
                    flag = false;
                    break;
                }
            }
            if(flag) ans = min(ans, cnt);
            cnt = 0;
            flag = true;
            for(int j = 0; j < n; j++) {
                if(bottoms[j] == i) continue;
                if(tops[j] == i) cnt++;
                else {
                    flag = false;
                    break;
                }
            }
            if(flag) ans = min(ans,cnt);
        }
        return ans == 1e9 ? -1 : ans;
    }
};
*/