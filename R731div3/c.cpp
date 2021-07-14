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
    int k,n,m;
    cin>>k>>n>>m;
    vector<int> a(n),b(m);
    for(auto &it:a) cin>>it;
    for(auto  &it:b) cin>>it;
    int one=0,two=0;
    vector<int> ans;
    for(int i=0;i<n+m;i++){
        if(one<n){
            if(a[one]==0){
                ans.push_back(a[one]);
                ++k,++one;
            }
            else if(a[one]<=k){
                ans.push_back(a[one]);
                ++one;
            }
        }
        if(two<m){
            if(b[two]==0){
                ans.push_back(b[two]);
                ++k,++two;
            }
            else  if(b[two]<=k){
                ans.push_back(b[two]);
                ++two;
            }
        }
    }
    if((int)ans.size()==n+m){
        for(auto x:ans) cout<<x<<" ";
    }
    else  cout<<-1;
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




