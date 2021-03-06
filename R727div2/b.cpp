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
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<ll> pref(n+1);
    ll tot=0;
    for(int i=1;i<=n;i++){
        ll val=s[i-1]-'a'+1ll;
        tot+=(val);
        pref[i]=val+pref[i-1];
    }
    while(q--){
        int l,r;cin>>l>>r;
        cout<<pref[r]-pref[l-1]<<"\n";
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




