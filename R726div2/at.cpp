#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
ll bp(ll a,ll b,ll mod=LONG_LONG_MAX){
    a%=mod;
    ll res=1;
    while(b>0){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return res;
}

vector<bool> vis(200001);
vector<int> adj[200001];
void dfs(int u){
    if(!vis[u]) return;
    vis[u]=false;
    for(auto v:adj[u]) dfs(v);
}
void solve(){
    int n;cin>>n;
    vector<int> v(n);
    int cnt=0;
    for(auto &it:v) {
        cin>>it;
        if(vis[it]==false){
            ++cnt;
            vis[it]=true;
        }
    }
    for(int i=0;i<(n/2);i++){
        adj[v[i]].push_back(v[n-i-1]);
        adj[v[n-i-1]].push_back(v[i]);
    }
    for(int i=1;i<=200000;i++){
        if(vis[i]){
            --cnt;
            dfs(i);
        }
    }
    cout<<cnt;
}

int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
//cin>>ttt;
while(ttt--){
    solve();
}
}




