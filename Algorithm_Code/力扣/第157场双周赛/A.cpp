/*
//模拟、set去重、排序
class Solution {
public:
    bool isprime(long long a) {
        if(a < 2) return false;
        for(long long i = 2; i * i <= a; i++) {
            if(a % i == 0) return false;
        }
        return true;
    }
    
    long long sumOfLargestPrimes(string s) {
        long long ans = 0;
        set<long long> se;
        vector<long long> v;
        int n = s.size(); 
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                long long sum = 0;
                for(int k = i; k <= j; k++) {
                    long long cur = s[k] - '0';
                    sum *= 10;
                    sum += cur;
                }
                if(isprime(sum)) se.insert(sum);
            }
        }
        for(auto &cur : se) v.push_back(cur);
        sort(v.begin(),v.end(), [&](const long long & a, const long long & b) -> bool{return a > b;});
        int k = v.size();
        for(int i = 0; i < min(3,k); i++) ans += v[i];
        return ans;
    }
};
*/