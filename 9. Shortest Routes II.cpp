// Standard problem Floyd Warshall Algo.

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
// const unsigned int M = 1000000007;
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
int dis[N][N];
void solve(){
    int n,m,q; cin>>n>>m>>q;
    int M = 1000000000000;
    rep(i,1,n+1) rep(j,1,n+1) dis[i][j]=M;
    rep(i,0,m){
        int u,v,w; cin>>u>>v>>w;
        dis[u][u]=0, dis[v][v]=0;
        dis[u][v]=min(dis[u][v],w), dis[v][u]=min(dis[u][v],w);
    }
    rep(k,1,n+1){
        rep(i,1,n+1){
            rep(j,1,n+1){
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    rep(i,0,q){
        int a,b; cin>>a>>b;
        if (dis[a][b]<M)cout<<dis[a][b]<<nl;
        else cout<<-1<<nl;
    }
}
 
signed main(){
    IOS;
    solve();

}