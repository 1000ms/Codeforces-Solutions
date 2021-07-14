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
const ll MOD=1e9+7;
void solve(){
    ll n;cin>>n;
    ll sum=0;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            sum=(sum+i)%MOD;
            if(n/i!=i) sum=(sum+n/i)%MOD;
        }
    }
    cout<<sum;
}
int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
//cin>>ttt;
while(ttt--){
    solve();
}
}




