#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    int h, w, n;
    cin >> h >> w >> n;
    
    // 存储每行/每列的垃圾坐标
    map<int, vector<int>> row; // row[x] 存储第x行的所有列坐标
    map<int, vector<int>> col; // col[y] 存储第y列的所有行坐标
    
    // 记录每行/每列的垃圾数量
    vector<int> r(h + 1, 0);
    vector<int> c(w + 1, 0);
    
    // 记录已清空的行/列
    vector<bool> cleared_row(h + 1, false);
    vector<bool> cleared_col(w + 1, false);
    
    // 输入垃圾坐标
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        r[x]++;
        c[y]++;
        row[x].push_back(y);
        col[y].push_back(x); // 修正：之前错误地写成row[y].push_back(x)
    }
    
    int q;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        
        if(a == 1) { // 查询行
            if(cleared_row[b]) {
                cout << 0 << endl;
                continue;
            }
            
            cout << r[b] << endl;
            
            // 清空该行的所有垃圾
            for(int y : row[b]) {
                if(!cleared_col[y]) {
                    c[y]--;
                }
            }
            
            cleared_row[b] = true;
            r[b] = 0;
        } else { // 查询列
            if(cleared_col[b]) {
                cout << 0 << endl;
                continue;
            }
            
            cout << c[b] << endl;
            
            // 清空该列的所有垃圾
            for(int x : col[b]) {
                if(!cleared_row[x]) {
                    r[x]--;
                }
            }
            
            cleared_col[b] = true;
            c[b] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}