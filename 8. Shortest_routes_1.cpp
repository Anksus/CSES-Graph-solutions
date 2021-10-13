// standard problem SSSP

#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define int64 int64_t
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long 
#define pll pair<ll,ll>
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
vector<pii>monster; 
pii start; pii ending; 
int dx[4] = {0,-1,1,0};
int dy[4] = {1,0,0,-1};
string path = "RUDL";
 
 
void solve(){
    ll n,m;
    cin>>n>>m;
    vec(vec(pll))g(n+1);
    rep(i,0,m){
        int from,to,cost; cin>>to>>from>>cost;
        g[to].pb({from,cost});
    }
    // for(int i=0;i<g.size();i++){
    //     cout<<i<<" ->";
    //     for(auto x:g[i]){
    //         cout<<x.first<<" ";
    //     }
    //     cout<<nl;
    // }
    vec(ll)dis(n+1,1e16);
    dis[1]=0;
    priority_queue<pll,vec(pll),greater<pll>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        int v = pq.top().second;
        int dis_v = pq.top().first;
        pq.pop();
        if(dis_v!=dis[v])continue;
//         for(auto x: g[v]){
//             int len = x.second; int to = x.first;
//             if(dis_v + len < dis[to]){
//                 dis[to] = dis_v + len;
//                 pq.push({dis[to],to});
//             }
//         }
     for(auto x: g[v]){
            int len = x.second; int to = x.first;
            if(dis_v + len < dis[to]){
                dis[to] = dis_v + len;
                pq.push({dis[to],to});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}
 
signed main(){
    IOS;
    solve();

}
