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
const int maxn=1e5+5;
ll low[maxn],high[maxn];
vector<vector<int>> adj;
pair<ll,ll> dfs(int v,int par){
    ll one=0,two=0;
    for(auto u:adj[v]){
        if(u==par) continue;
        pair<ll,ll> down=dfs(u,v);
        one+=max(abs(low[v]-low[u])+down.first,abs(low[v]-high[u])+down.second);
        two+=max(abs(high[v]-low[u])+down.first,abs(high[v]-high[u])+down.second);
    }
    return {one,two};
}
void solve(){
int n;cin>>n;
adj=vector<vector<int>>(n);
for(int i=0;i<n;i++) cin>>low[i]>>high[i];
for(int i=1;i<n;i++){
    int x,y;cin>>x>>y,x--,y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
pair<ll,ll> ans=dfs(0,-1);
cout<<max(ans.first,ans.second)<<"\n";
}
int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
cin>>ttt;
while(ttt--){
    solve();
}
}




