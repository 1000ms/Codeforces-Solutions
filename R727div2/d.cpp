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

bool comp(const pair<ll,ll> &a,const pair<ll,ll> &b){
    if(a==b) return false;
    if(a.second!=b.second) return a.second>b.second;
    else return a.first>b.first;
}

void solve(){
    int n;cin>>n;
    vector<pair<ll,ll>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end(),comp);
    ll cur=0,ans=0;
    int l=0,r=n-1;
    //for(auto x:v) cout<<x.first<<" "<<x.second<<endl;
    while(l<=r){
        while(l<=r && cur<v[r].second){
            ll taken=min(v[l].first,v[r].second-cur);
            ans+=taken*2ll;
            cur+=taken;
            v[l].first-=taken;
            if(v[l].first==0) ++l;
        }
        while(l<=r && cur>=v[r].second){
            ans+=v[r].first;
            cur+=v[r].first;
            --r;
        }
    }
    cout<<ans;
}

int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
//cin>>ttt;
while(ttt--){
    solve();
}
}




