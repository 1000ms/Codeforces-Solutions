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
ll x,y,a,b;
bool good(ll m){
    ll X=x,Y=y;
    X-=m*a,Y-=m*a; 
    bool ok=(X>=0 && Y>=0); 
    if(b>a){
        if(X/(b-a)+Y/(b-a)<m) ok=false; 
    }
    return ok;
}
void solve(){
    cin>>x>>y>>a>>b;
    if(a>b) swap(a,b);
    ll l=-1,r=1e9+5;
    while(l+1<r){
        ll m=(l+r)/2; 
        if(good(m)) l=m; 
        else r=m;
    }
    cout<<l<<"\n";
}
int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
cin>>ttt;
while(ttt--){
    solve();
}
}




