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
    int naxp,nimp;
    for(int  i=0;i<n;i++){
        cin>>v[i];
        if(v[i]==n) naxp=i;
        if(v[i]==1) nimp=i;
    }
    if(naxp<nimp) swap(naxp,nimp);
    int one=max(naxp+1,nimp+1);
    int two=max(n-naxp,n-nimp);
    int three=nimp+1+n-naxp;
    cout<<min({one,two,three})<<"\n";
}
int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
cin>>ttt;
while(ttt--){
    solve();
}
}




