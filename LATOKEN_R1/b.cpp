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
    int n;
    cin>>n;
    //decrease end also to 0
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(n==1){
        cout<<v[0]<<"\n";
        return;
    }
    ll tot=0;
    for(int i=1;i<n-1;i++){
        if(v[i]>v[i-1] && v[i]>v[i+1]){
            tot+=v[i]-max(v[i-1],v[i+1]);
            v[i]=max(v[i-1],v[i+1]);
        }
    }
    if(v[0]>v[1]){
        tot+=v[0]-v[1];
        v[0]=v[1];
    }
    if(v[n-1]>v[n-2]){
        tot+=v[n-1]-v[n-2];
        v[n-1]=v[n-2];
    }
    tot+=v[0]+v[n-1];
    for(int i=1;i<n;i++){
        tot+=abs(v[i]-v[i-1]);
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




