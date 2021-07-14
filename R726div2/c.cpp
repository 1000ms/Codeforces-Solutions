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
    for(auto &it:v) cin>>it;
    sort(v.begin(),v.end());
    ll diff=LONG_LONG_MAX;
    ll val1=-1,val2=-1;
    for(int i=n-1;i>0;i--){
        if(v[i]-v[i-1]<=diff){
            val1=i-1,val2=i;
            diff=v[i]-v[i-1];
        }
    }
    assert(val1!=-1 && val2!=-1);
    cout<<v[val1]<<" ";
    for(int i=val2+1;i<n;i++){
        cout<<v[i]<<" ";
    }
    for(int i=0;i<val1;i++){
        cout<<v[i]<<" ";
    }
    cout<<v[val2]<<"\n";
}

int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
cin>>ttt;
while(ttt--){
    solve();
}
}




