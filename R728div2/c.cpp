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
    ll n;cin>>n;
    vector<ll> v(n);
    for(auto &it:v) cin>>it;
    sort(v.begin(),v.end());
    ll tot=0;
    for(ll i=0;i<n-1;i++){
        tot+=v[i+1]-v[i];
        tot+=(v[i]-v[i+1])*((i+1ll)*(n-(i+1ll)));
    }
    cout<<tot<<"\n";
}

int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
cin>>ttt;
while(ttt--){
    solve();
}
}




