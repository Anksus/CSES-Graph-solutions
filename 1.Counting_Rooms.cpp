#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define nl '\n'
int n, m;
vector<int>dir = {0, -1, 0, 1, 0};
void dfs(vector<vector<int>>& vis, vector<vector<char>>& a, int i, int j) {
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int x = i + dir[k], y = j + dir[k + 1];
        if (min(x, y) >= 0 && x < n && y < m && !vis[x][y] && a[x][y] == '.') {
            dfs(vis, a, x, y);
        }
    }
}
 
void solve() {
    cin >> n >> m;
    vector<vector<char>>a(n, vector<char>(m, 0));
    vector<vector<int>>vis(n, vector<int>(m, 0));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> a[i][j];
//         }
//     }
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<m;j++)
  {
   cin>>a[i][j];
  }
 }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.' && !vis[i][j]) {
                ans++;
                dfs(vis, a, i, j);
            }
        }
    }
 
    cout << ans;
 
}
 
 
int main()
{
    IOS;
// Windows env
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif
    // int t; cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
 
    solve();
}
