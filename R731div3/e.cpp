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
    int n,k;
    cin>>n>>k;
    vector<ll> v(n,1e12);
    vector<pair<int,int>> temp(k);
    for(int i=0;i<k;i++){
        cin>>temp[i].second,--temp[i].second;
    }
    for(int i=0;i<k;i++){
        cin>>temp[i].first;
        assert(temp[i].second<n);
        v[temp[i].second]=temp[i].first;
    }
    sort(temp.begin(),temp.end());
    for(int i=0;i<k;i++){
        int l=temp[i].second-1;
        int r=temp[i].second+1;
        while(l>=0 && temp[i].first+temp[i].second-l<v[l]){
            v[l]=temp[i].first+temp[i].second-l;
            --l;
        }
        while(r<n && temp[i].first+r-temp[i].second<v[r]){
            v[r]=temp[i].first+r-temp[i].second;
            ++r;
        }
    }
    for(auto x:v) cout<<x<<" ";
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




