// Problem is asking for disconnected components and how we can connect them.

#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define nl '\n'
 
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MN = 1e5 + 10;
vector<int>g[MN];
bool vis[MN];
int rep[MN];
int n, m;
 
void dfs(int v) {
    vis[v] = true;
    for (auto x : g[v]) {
        if (!vis[x])dfs(x);
    }
}
 
int count_component() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            rep[cnt++] = i;
            dfs(i);
        }
    }
    return cnt;
}
 
void solve() {
    // int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y); g[y].push_back(x);
    }
    int b = count_component();
    cout << b - 1 << nl;
    for (int i = 1; i < b; i++) {
        cout << rep[i - 1] << " " << rep[i] << " ";
    }
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