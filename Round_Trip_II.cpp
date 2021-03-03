
// video link to understand the solution. https://www.youtube.com/watch?v=rKQaZuoUR4M
// We have to detect a cycle in a directed graph.


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
std::vector<int>a[N],par(N,0),vis(N,0);
bool act[mxN]; 

void dfs(int u,int pu){
    par[u] = pu;
    vis[u]=1;
    act[u]=1;
    for(auto x: a[u]){
        
        if(act[x]){
            vector<int>ans;
            ans.pb(u);
            int temp = u;
            while(par[temp]!=x){
                temp = par[temp];
                ans.pb(temp);
            }
            ans.pb(x);
            ans.pb(u);
            reverse(all(ans));
            cout<<ans.size()<<nl;
            for(auto x:ans){
                cout<<x<<" ";
            }
            exit(0);
        }else{
            dfs(x,u);
        }
    }
    act[u]=0;
}

void solve(){
    int n,m;
    cin>>n>>m;
    rep(i,0,m){
        int x,y; cin>>x>>y;
        a[x].pb(y);
    }
    rep(i,1,n+1){
        if(!vis[i]){
            dfs(i,-1);
        }
    }
    cout<<"IMPOSSIBLE";
}


int main(){
    IOS;
    solve();
}