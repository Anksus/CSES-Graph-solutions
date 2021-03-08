// While recurring to the destination node, we set all the nodes to 0. 
// but the last one to 1 and getting this values pass to all the routes back,
// so that they can be collected back at 1st node.

//  act[mxN] is for detecting cycle, just a bellman ford stuff.

// There are 2 approach to solve this problem (according to my knowledge).
// 1. Traditional BFS (gives TLE for large N)
// 2. DP + DFS (works like a charm)

#include <bits/stdc++.h>
using namespace std;
 
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
int n,m,k,q;
const int mxN=2e5;
const int N = 100031;
bool bad = false;
std::vector<int>a[N],par(mxN,0),vis(mxN,0);
int dp[mxN]; 
vi adj[mxN];  int act[mxN];
vector<pii> g[mxN];
 

void dfs(int u){
    dp[u] = u==n?1:0;
    vis[u]=1;
    act[u]=1;
    for(auto x: adj[u]){
        if(act[x]){
            cout<<"IMPOSSIBLE";
            exit(0);
        }else if(!vis[x]){
            par[x]=u;
            dfs(x);
        }
        dp[u] = (dp[x]+dp[u])%M;
    }
    act[u]=0;
}

void solve(){
    cin>>n>>m;
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }
    par[1]=-1;
    rep(i,1,n+1){
        if(!vis[i]){
            dfs(i);
        }
    }
    cout<<dp[1];
}
 
 
int main(){
    IOS;
    solve();
}