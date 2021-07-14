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
vector<int> v(n);
for(auto &it:v) cin>>it;
ll ans=0;
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(__gcd(v[i],2*v[j])>1 || __gcd(v[j],2*v[i])>1) ans+=1;
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




