/*
//贪心+模拟
class Solution {
public:
    int maxSubstrings(string word) {
        vector<int> idx(26, -1);
        int n = word.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int inx = word[i] - 'a';
            if(idx[inx] == -1) idx[inx] = i;
            else {
                if(i - idx[inx] + 1 >= 4) {
                    //cout << idx[inx] << " " << i;
                    ans++;
                    for(int j = 0; j < 26; j++) idx[j] = -1;
                }
            }
        }
        return ans;
    }
};
*/