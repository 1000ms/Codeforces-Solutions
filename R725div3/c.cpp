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
    ll n,l,r;cin>>n>>l>>r;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    if(n==1){
        cout<<0<<"\n";
        return;
    }
    vector<ll> pref;
    pref.push_back(v[0]);
    ll ans=0;
    for(int i=1;i<n;i++){
        if(v[i]>=r) break;
        ll req=r-v[i];
        ll left=l-v[i];
        auto high=upper_bound(pref.begin(),pref.end(),req)-pref.begin();
        auto low=lower_bound(pref.begin(),pref.end(),left)-pref.begin();
        ans+=high-low;
        pref.push_back(v[i]);
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




