/*
//遍历s，记录各个字母的个数和下标，同时维护最小字母mi，遇到则删除最小字母mi的最后一个下标（即最右边的下标）并将该坐标字母更新为同时更新mi的值，最后遍历s的时候跳过字母为*的即可。
//技巧在于维护最小值的方法和一些小细节的处理。
class Solution {
public:
    string clearStars(string s) {
        vector<int> cnt(26, 0);
        vector<vector<int>> v(26);
        int n = s.size();
        int mi = 26;
        for(int i = 0; i < n; i++) {
            if(s[i] == '*') {
                s[v[mi][cnt[mi] - 1]] = '*';
                cnt[mi]--;
                v[mi].pop_back();
                while(mi < 26 && cnt[mi] == 0) mi++; 
                continue;
            }
            int idx = s[i] - 'a';
            v[idx].push_back(i);
            mi = min(mi, idx);
            cnt[idx]++;
        }
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(s[i] == '*') continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};
*/