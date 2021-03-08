// Bellman ford
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define int64 int64_t
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long 
#define pb push_back
#define str string
#define ri(x) int x;cin>>x;
#define rl(x) ll x; cin>>x;
#define rs(x) str x; cin>>x;
#define rd(x) d x; cin>>x;
#define w(x) cout<<x;
#define vec(x) std::vector<x> 
#define nl '\n'
#define all(x) x.begin(),x.end() 
#define map_traverse(it,x)  for(auto it = BN(x); it!= ED(x); it++)      
#define debug(x) for(auto y : x) {cout<<y<<" ";} cout<<nl;
#define PI 3.14159265358979323846264338327950L
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
const unsigned int M = 1000000007;
const int mxN=2e5;
// const int N = 100031;
bool bad = false;
vector<pii>monster; 
int n,m,q;
const ll inf = INT_MAX;
pii start; pii ending;
int dx[4] = {0,-1,1,0};
int dy[4] = {1,0,0,-1};
string path = "RUDL";
 
const int N = 505;
// int dis[N][N];
 
vi adj[2505],adj2[2505];
int dis[2505];
bool  vis[2505],vis2[2505];
 
void dfs(int v){
    if(vis[v])return;
    vis[v]=1;
    for(auto x: adj[v] )dfs(x);
}
 
void dfs2(int v){
    if(vis2[v])return;
    vis2[v]=1;
    for(auto x: adj2[v])dfs2(x);
}
 
void solve(){
    
    cin>>n>>m;
    rep(i,1,n+1)dis[i]=1e16;
    dis[1]=0; vector<tuple<int,int,int>>e;
    rep(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        e.pb({u,v,-w});
        adj[u].pb(v); adj2[v].pb(u);
    }
    dfs(1); dfs2(n);
    rep(i,0,n){
        for(auto [a,b,w] : e){   // destructuring c++17 
            if(dis[b]>dis[a]+w){
                dis[b] = dis[a]+w;
                if(i==n-1 && vis[b] && vis2[b]){
                    cout<<-1<<nl;
                    return;
                }
            }
        }
    }
    cout<<-dis[n]<<nl;
} 
 
signed main(){
    IOS;
    solve();
}