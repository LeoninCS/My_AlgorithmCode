/*
//sort+lambda排序,map记位置
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> v(nums);
        sort(v.begin(),v.end(),[&](const int &a,const int &b)->bool {
            int cnta = 0; 
            int cntb = 0; 
            int tema = a, temb = b;
            while(tema) {
                cnta += tema % 10;
                tema /= 10;
            }
            while(temb) {
                cntb += temb % 10;
                temb /= 10;
            }
            if(cnta == cntb) return a < b;
            else return cnta < cntb;
        });
        int cnt = 0;
        int n = nums.size();
        map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            //cout << v[i] << " ";
            if(nums[i] == v[i]) continue;
            else {
                int idx = mp[v[i]];
                mp[v[i]] = i;
                mp[nums[i]] = idx;
                swap(nums[i],nums[idx]);
                cnt++;
                //for(int i = 0; i < n; i++) cout << nums[i] << " ";
                //cout << endl;
            }
        }
        //for(int i = 0; i < n; i++) cout << v[i] << " ";
        return cnt;
    }
};
*/