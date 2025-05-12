/*
//贪心
class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> cnt(26,0);
        int n = s.size();
        for(int i = 0 ; i < n; i++) {
            int idx = s[i] - 'a';
            cnt[idx]++;
        }
        sort(cnt.begin(),cnt.end(),[&](const int a, const int b)->bool{return a > b;});
        int ans = 0;
        int temk = 0;
        for(int i = 0; i < 25; i++) {
            if(cnt[i] == 0) continue;
            temk++;
            ans += cnt[i];
            if(temk == k) break;
        }
        return n - ans;
    }
};
*/