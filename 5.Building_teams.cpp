// Bipartite graph

#include <bits/stdc++.h>
using namespace std;
 
#define P pair<int,int>
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
const unsigned int M = 1000000007;
const int mxN=2e5;
const int N = 100031;
bool bad = false;
vec(int)vis(N,0);
std::vector<int>a[N],group(N,0);
 
void dfs(int i,int g=0){
    vis[i] = 1;
    group[i]=g;
    for(auto x: a[i]){
        if(vis[x]){
            if(group[x]==g)bad = 1;
        }else{
            dfs(x,!g);
        }
    }
}
 
void solve(){
    int n,m;
    cin>>n>>m;
    rep(i,0,m){
        int x,y; cin>>x>>y;
        a[x].pb(y); a[y].pb(x);
    }
    for(int i=1;!bad&&i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    if(bad){
        cout<<"IMPOSSIBLE"<<nl;
        return;
    }
    for(int i=1;i<=n;i++){
        cout<<group[i]+1<<" ";
    }
}
 
 
int main(){
    IOS;
    solve();
}