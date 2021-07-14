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

ll n,k,x;
vector<ll> v;
vector<ll> diff;
vector<ll> pref;
bool good(ll m){
    //we can do m-1  partitons
    ll sz=(ll)diff.size();
    if(sz<=(m-1ll)) return true;
    ll tot=pref[sz]-pref[m-1];
    //cout<<tot<<endl;
    return tot<=k;
}
void solve(){
    cin>>n>>k>>x;
    v=vector<ll>(n);
    for(auto &it:v) cin>>it;
    sort(v.begin(),v.end());
    for(int i=1;i<n;i++){
        if((v[i]-v[i-1])>x){
            diff.push_back(((v[i]-v[i-1]+x-1)/x)-1);
        }
    }
    if((int)diff.size()==0){
        cout<<1<<"\n";
        return;
    }
    sort(diff.rbegin(),diff.rend());
    pref=vector<ll>((int)diff.size()+1);
    for(int i=1;i<=(int)diff.size();i++){
        pref[i]=pref[i-1]+diff[i-1];
    }
    ll l=0,r=200005;
    while(l+1<r){
        ll m=(l+r)/2;
        if(good(m)) r=m;
        else l=m;
    }
    cout<<r<<"\n";
}

int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
//cin>>ttt;
while(ttt--){
    solve();
}
}




