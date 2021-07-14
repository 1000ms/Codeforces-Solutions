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
    ll a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    if(a==b){
        cout<<0<<" "<<0<<"\n";
        return;
    }
    ll diff=b-a;
    if(b%diff==a%diff){
        cout<<diff<<" "<<min(a%diff,diff-(a%diff))<<"\n";
    }
    else{
        cout<<__gcd(a,b)<<" "<<0<<"\n";
    }
}

int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
cin>>ttt;
while(ttt--){
    solve();
}
}




