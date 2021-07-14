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
int n;cin>>n;
vector<ll> v(n);
for(auto &it:v) cin>>it;
sort(v.begin(),v.end());
vector<ll> diff(n);
for(int i=1;i<n;i++){
    diff[i]=v[i]-v[i-1];
}
ll ans=1;
ll nim=LONG_LONG_MAX;
for(int r=1;r<n;r++){
    nim=min(nim,diff[r]);
    if(v[r]<=nim) ans=r+1;
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




