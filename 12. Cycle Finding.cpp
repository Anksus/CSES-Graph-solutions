// Bellman ford 
// https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html

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
 
// vi adj[mxN],adj2[2505];
int dis1[mxN]; int dis2[mxN];
// bool  vis[2505],vis2[2505];
vi par(mxN,0);
// vector<pii>adj[mxN],adj2[mxN];
 
 
 
 
void solve(){
    cin>>n>>m;
    vector<tuple<int,int,int>>e;
    rep(i,0,m){
        int u,v,w; cin>>u>>v>>w;
        e.pb({u,v,w});
    }
    rep(i,1,n+1)dis1[i]=1e16;
    dis1[1]=0;
    int x;
    rep(i,0,n){
        x = 0;
        for(auto [a,b,w]: e){     // destructuring c++17 feature
            if(dis1[b]>dis1[a]+w){
                dis1[b] = dis1[a] +w;
                par[b] = a;
                x = b;
            }
        }
    }
    if(!x)cout<<"NO"<<nl;
    else{
        cout<<"YES"<<nl;
        vec(int)cycle; int y = x;
        rep(i,0,n)y= par[y];
        for(int v = y; ; v= par[v]){
            cycle.pb(v);
            if(cycle.size()>1 && v==y)break;
        }
//         reverse(all(cycle));
//         for(auto xx: cycle){
//             cout<<xx<<" ";
//         }
        reverse(all(cycle));
        for(auto xx: cycle){
            cout<<xx<<" ";
        }
    }
}
 
signed main(){
    IOS;
    solve();
}
