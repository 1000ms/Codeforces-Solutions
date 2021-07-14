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
void solve(){
int n;
cin>>n;
vector<ll> v(n);
for(auto &it:v) cin>>it;
vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1e16));
//for(int i=1;i<=n;i++) dp[i-1][i-1]=v[i];

for(int i=1;i<=n;i++){
    dp[0][i]=-1e16;
    dp[i][0]=0;
}
dp[0][0]=0;
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        ll val=v[i-1];
        if(dp[i-1][j-1]+val>=0){
            dp[i][j]=max(dp[i-1][j-1]+val,dp[i-1][j]);
        }
        else dp[i][j]=dp[i-1][j];
    }
}
for(int i=n;i>=0;i--){
    if(dp[n][i]>=0){
        cout<<i<<"\n";
        return;
    }
}
}
int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
//cin>>ttt;
while(ttt--){
    solve();
}
}




