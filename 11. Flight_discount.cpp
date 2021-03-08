// Do Dijsktra from 1st and last node, so we can have min cost from both the sides.
// Loop through all the nodes and check for the min cost.

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
// vi par(mxN,0);
vector<pii>adj[mxN],adj2[mxN];
 
void dij(int src,vector<pii> adj[mxN], int dis[mxN]){
    memset(dis,0x3f,sizeof(dis2));
    dis[src]=0;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto p = pq.top();
        int v = p.second, dis_v = p.first;
        pq.pop();
        if(dis_v!=dis[v])continue;
        for(auto x: adj[v]){
            int to = x.first, len = x.second;
            if(dis[to]> dis[v]+ len){
                dis[to] = dis[v]+len;
                pq.push({dis[to],to});
            }
        }
    }
 
}
 
 
void solve(){
    cin>>n>>m;
    rep(i,0,m){
        int u,v,w; cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj2[v].pb({u,w});
    }
    dij(1,adj,dis1);
    dij(n,adj2,dis2);
    int ans = 1e18;
    rep(i,1,n+1){
        for(auto x: adj[i]){
            ans = min(ans, dis1[i]+dis2[x.first]+ x.second/2);
        }
    }
    cout<<ans<<nl;
}
 
signed main(){
    IOS;
    solve();
}