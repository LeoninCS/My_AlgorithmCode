/*
//模拟
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int sum = 0;
            while(nums[i]) {
                sum += nums[i] % 10;
                nums[i] /= 10;
            }
            //cout << sum << " ";
            if(sum == i) return i;
        }
        return -1;
    }
};
*/