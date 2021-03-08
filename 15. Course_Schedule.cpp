// Topological sort - standard problem
// Video https://www.youtube.com/watch?v=ddTC4Zovtbc&t=1s
// https://cp-algorithms.com/graph/topological-sort.html

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
const int mxN=2e5;
const int N = 100031;
bool bad = false;
std::vector<int>a[N],par(N,0),vis(N,0);
int indeg[mxN];
vi adj[mxN]; 
 
void solve(){
    int n,m; cin>>n>>m;
    rep(i,0,m){
        int u,v; cin>>u>>v;
        adj[u].pb(v); indeg[v]++;
    }
    vi ans;
    queue<int>q; int cnt = 0;
    rep(i,1,n+1){
        if(indeg[i]==0){
            q.push(i);
            cnt++; ans.pb(i);
        }
    }
    while(!q.empty() && cnt<=n){
        int p = q.front(); q.pop();
        for(auto x: adj[p]){
            if(--indeg[x]==0){
                ans.pb(x);
                q.push(x);
            }
        }
    }
    if(ans.size()==n){
        debug(ans);
    }else{
        cout<<"IMPOSSIBLE";
    }
}
 
 
int main(){
    IOS;
    solve();
}