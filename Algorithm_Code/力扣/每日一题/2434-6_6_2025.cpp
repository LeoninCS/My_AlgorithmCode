/*
//贪心+栈的应用
class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for(int i = 0; i < n ; i++) {
            int idx = s[i] - 'a';
            cnt[idx]++;
        }
        int inx = 0;
        int end = 26;
        string ans = "";
        stack<char> t;
        for(int i = 0; i < n; i++) {
            while(inx < 26 && cnt[inx] == 0) inx++; 
            //cout << ans << "~~" << (char)(inx + 'a') << endl;
            if(inx < end) {
                int idx = s[i] - 'a';
                if(idx == inx) {
                    ans.push_back(s[i]);
                    cnt[idx]--; 
                } else {
                    t.push(s[i]);
                    cnt[idx]--;
                    end = idx;
                }
            } else {
                while(t.size()) {
                    char tp = t.top();
                    //cout << ans << "--" << (char)(inx + 'a') << "--" << tp << endl;
                    if(end <= inx) {
                        ans.push_back(tp);    
                        t.pop();
                        if(t.size() == 0) {
                            end = 26;
                            break;
                        }
                        tp = t.top();
                        end = tp - 'a';
                    } else break;
                }
                int idx = s[i] - 'a';
                t.push(s[i]);
                cnt[idx]--;
                end = idx;
            }
        }
        while(t.size()) {
            char tp = t.top();
            t.pop();
            ans.push_back(tp);
        }
        return  ans;
    }
};
*/