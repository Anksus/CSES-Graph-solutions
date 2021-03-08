// First fill the matrix with the monsters like at which time they will be there in that particular cell
// After that, do bfs on A. Push only that co-odinates, which aren't vulnerable at that time.
// resource https://www.youtube.com/watch?v=hB59dxdDLII

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
bool bad = false;
vector<pii>monster;
pii start; pii ending; int n,m;
int dx[4] = {0,-1,1,0};
int dy[4] = {1,0,0,-1};
string path = "RUDL";
vector<vector<int>>previousstep(1000,vector<int>(1000,0)),a(1000,vector<int>(1000,0));
 
// bool isValid(int x,int y,int timer){
//     // if(min(x,y)>=0 && x<n && y<m && a[x][y]>timer)return true;
//     return false;
// }
bool isValid(int x, int y, int timer)
{
    if(min(x,y)>=0 && x<n && y<m && a[x][y]>timer)return true;
    return false;
}
 
bool isEscape(int x,int y,int timer){
    if(!isValid(x,y,timer))return false;
    if(x==0 || y == 0 || x == n-1 || y==m-1 )return true;
    return false;
}
 
bool bfs_for_player(){
    
    queue<pair<pii,int>>q;
    q.push(make_pair(start,0));
    while(!q.empty()){
        auto p = q.front(); q.pop();
        int i = p.first.first, j = p.first.second;
        int timer = p.second;
        timer++;
        for(int k=0;k<4;k++){
            int x = i + dx[k] , y = j+dy[k];
            if(isEscape(x,y,timer)){
                previousstep[x][y] = k;
                ending = make_pair(x,y); return true;
            }
            if(isValid(x,y,timer)){
                previousstep[x][y] = k;
                q.push({{x,y},timer});
                a[x][y]=timer;
            }
        }
    }
    return false;
}
 
 
 
 
void lava_preprocess(){
    queue<pair<pii,int>>q;
    for(auto x:monster){
        q.push({x,0});
    }
    while(!q.empty()){
        auto p = q.front(); q.pop();
        int i = p.first.first, j = p.first.second;
        int timer = p.second;
        timer++;
        for(int k=0;k<4;k++){
            int x = i + dx[k], y = j + dy[k];
            if(isValid(x,y,timer)){
                a[x][y] = timer;
                q.push({{x,y},timer});
            }
        }
    }
}
 
void solve(){
    cin>>n>>m;
    // vec(vec(int))a(n,vec(int)(m,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x; cin>>x;
            if(x=='M'){
                monster.pb({i,j});
                a[i][j]=0;
            }else if(x=='#')a[i][j]=0;
            else if(x=='A'){
                start={i,j};
                a[i][j]=0;
            }else{
                a[i][j]=INT_MAX;
            }
        }
    }
    if(start.first==0 || start.second==0 || start.first == n-1 || start.second == m-1){
        cout<<"YES"<<nl; cout<<0<<nl; return;
    }
    // cout<<start.first<<" "<<start.second;
    // cout<<"IMPOSSIBLE";
    lava_preprocess();
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<nl;
    // }
    if(!bfs_for_player()){
        cout<<"NO";return;
    }
    // cout<<ending.first<<" ";
    cout<<"YES"<<nl;
    vector<int>steps;
    while(ending!=start){
        int p = previousstep[ending.first][ending.second];
        steps.push_back(p);
        ending = {ending.first-dx[p],ending.second - dy[p]};
    }
    cout<<steps.size()<<nl;
    reverse(all(steps));
    for(auto x: steps){
        cout<<path[x];
    }
}
 
 
int main(){
    IOS;
    solve();

}