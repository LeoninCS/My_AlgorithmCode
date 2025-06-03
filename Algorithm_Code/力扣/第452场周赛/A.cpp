/*
// dfs
class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        vector<int> v;
        int n = nums.size();
        auto dfs = [&](auto dfs, int idx, long long sum) -> bool { 
            if(sum == target) return true;
            if(sum > target) return false;
            if(idx == n) return false;
            bool a1 = dfs(dfs, idx + 1, sum);
            if(a1) return a1;
            v.push_back(idx);
            bool a2 = dfs(dfs, idx + 1, sum * nums[idx]);
            if(a2) return a2;
            v.pop_back();
            return false;
        };
        bool ans = dfs(dfs, 0,1);
        set<int> se;
        for(auto & e: v) {
            se.insert(e);
            //cout << e << " ";
        } 
        long long sum = 1;
        for(int i = 0; i < n; i++) {
            if(se.count(i)) continue;
            sum *= nums[i];
            if (sum > target) return false;
        }
        if(sum != target) ans = false; 
        return ans;
    }
};
*/