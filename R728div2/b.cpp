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
    unordered_map<ll,int> m;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        m[x]=i+1;
    }
    ll ans=0;
    for(ll i=1;i<=2*n;i++){
        if(!m.count(i)) continue;
        for(ll j=i+1;j<=2*n;j++){
            if(i*j>=2*n) break;
            if(!m.count(j)) continue;
            if(i*j==m[i]+m[j]) ++ans;
        }
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




