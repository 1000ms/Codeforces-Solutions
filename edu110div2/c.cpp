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
    string s;cin>>s;
    int n=(int)s.size();
    vector<vector<int>> dp(n,vector<int>(2));
    dp[0][0]=(s[0]=='?' || s[0]=='0'?1:0);
    dp[0][1]=(s[0]=='?' || s[0]=='1'?1:0);
    ll ans=0;
    for(int i=1;i<n;i++){
        if(s[i]!='1')
            dp[i][0]=1+dp[i-1][1];
        if(s[i]!='0')
            dp[i][1]=1+dp[i-1][0];
    }
    for(int i=0;i<n;i++){
        ans+=max(dp[i][0],dp[i][1]);
    }
    cout<<ans<<"\n";
}
int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
cin>>ttt;
while(ttt--){
    solve();
}
}




