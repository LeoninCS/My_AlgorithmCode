/*
//栈的应用
class Solution {
public:
    string resultingString(string s) {
        int n = s.size();
        stack<char> sta;
        for(int i = 0; i < n; i++) {
            if(sta.empty()) sta.push(s[i]);
            else {
                int idx1 = s[i] - 'a';
                int idx2 = sta.top() - 'a';
                if(abs(idx1 - idx2) % 24 == 1) sta.pop();
                else sta.push(s[i]);
            }
        }
        string ans = "";
        while(!sta.empty()) {
            ans.push_back(sta.top());
            sta.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
*/