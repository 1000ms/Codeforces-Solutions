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
for(int i=0;i<n;i++){
    cin>>v[i];
}
ll ans=0;
ll val=*min_element(v.begin(),v.end());
for(int i=0;i<n;i++){
    if(v[i]>val) ans+=1;
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




