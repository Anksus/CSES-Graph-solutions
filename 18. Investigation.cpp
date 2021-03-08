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
int n,m,k,q;
const int mxN=2e5;
const int N = 100031;
bool bad = false;
std::vector<int>a[N],par(mxN,0),vis(mxN,0);
int dp[mxN]; 
vi adj[mxN];  int act[mxN];
vector<pii> g[mxN];
// vi cost[mxN],route[mxN],min_f[mxN],max_f[mxN];
vi cost(mxN),route(mxN),min_f(mxN),max_f(mxN);


void dij()
{
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,1});
	cost[1] = 0;
	route[1]=1;
	while(!q.empty()){
		auto p = q.top(); q.pop();
		int v = p.second, dis_v = p.first;
 
		if(dis_v>cost[v])continue;
		for(auto x: g[v]){
			int to = x.first, len = x.second;
			if(len+dis_v>cost[to])continue;
			if(dis_v+len==cost[to]){
				route[to]+=route[v];
				route[to]%=M;
				min_f[to] = min(min_f[v]+1,min_f[to]);
				max_f[to] = max(max_f[v]+1,max_f[to]);
			}
			if(len+dis_v<cost[to]){
				cost[to] = len+dis_v;
				route[to] = route[v];
				min_f[to] = min_f[v]+1;
				max_f[to] = max_f[v]+1;
				q.push({cost[to],to});
			}
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i <m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({v,c});
	}
	for(int i = 2; i <= n; ++i)
	{
		cost[i] = 1e16;
	}
	dij();
	cout << cost[n] <<" " <<route[n] <<" "<<min_f[n] <<" "<<max_f[n] << endl;
}