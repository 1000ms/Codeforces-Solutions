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
    for(auto &it:v) cin>>it;
    int last=v[0];
    vector<int> ans;
    ans.push_back(0);
    for(int i=1;i<n;i++){
        int val=0;
        for(int j=0;j<30;j++){
            if(((1<<j)&last)){
                if(!((1<<j)&v[i])) val|=(1<<j);
            }
        }
        last=(v[i]^val);
        ans.push_back(val);
    }
    for(auto x:ans) cout<<x<<" ";
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




