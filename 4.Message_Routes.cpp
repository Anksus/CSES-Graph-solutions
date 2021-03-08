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
const unsigned int M = 1000000007;
const int mxN=2e5;
const int N = 100031;
const int nax = 1e5+5;
vector<int > g[nax] , par(nax,0);
 
void solve(){
    int n,m;
    cin>>n>>m;
    // vec(vec(int))g;vec(int)par(mxN,0);
    rep(i,0,m){
        int a,b; cin>>a>>b;
        g[a].pb(b); g[b].pb(a);
    }
    // cout<<"hello";
    queue<int>q;
    q.push(1); par[1]=-1;
    while(!q.empty()){
        int p = q.front(); q.pop();
        for(auto x:g[p]){
            if(!par[x]){
                q.push(x);
                par[x]=p;
            }
        }
    }
    if(par[n]){
        stack<int>st;
        int p = par[n];
        st.push(n);
        while(p!=-1){
            st.push(p);
            p = par[p];
        }
        cout<<st.size()<<nl;
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
    }else{
        cout<<"IMPOSSIBLE"<<nl;
    }
} 
 
 
int main()
{ 
    IOS;
    // int t; cin>>t;
    // while (t--)
    // {
    //     solve();
    // }
 
    solve();
}