#include <bits/stdc++.h>
using namespace std;

vector<int> mul(vector<int>& v1, vector<int>& v2) 
{
    vector<int> res(v1.size() + v2.size(), 0);
    for (int i = 0; i < v2.size(); i++) {
        int carry = 0;
        for (int j = 0; j < v1.size(); j++) {
            int sum = v2[i] * v1[j] + res[i + j] + carry;
            res[i + j] = sum % 10;
            carry = sum / 10;
        }
        res[i + v1.size()] += carry;
    }

    while (res.size() > 1 && res.back() == 0) {
        res.pop_back();
    }
    return res;
}

int main()
{
    vector<int> ans(1, 1);
    int n = 0;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        vector<int> v;
        while (x > 0) {
            v.push_back(x % 10);
            x /= 10;
        }
        if (v.empty()) {
            v.push_back(0);
        }
        ans = mul(ans, v);
    }

    // Êä³ö½á¹û
    for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
        cout << *it;
    }
    cout << endl;
    return 0;
}

