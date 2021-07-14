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
    if(n%2==0){
        for(int i=1;i<=n;i+=2){
            cout<<i+1<<" "<<i<<" ";
        }
    }
    else {
        cout<<3<<" "<<1<<" "<<2<<" ";
        for(int i=4;i<=n;i+=2){
            cout<<i+1<<" "<<i<<" ";
        }
    }
    cout<<"\n";
}

int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
cin>>ttt;
while(ttt--){
    solve();
}
}




