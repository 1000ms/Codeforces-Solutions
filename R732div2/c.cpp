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
    map<int,vector<int>> init,fin;
    for(int i=0;i<n;i++){
        cin>>v[i];
        init[v[i]].push_back(i);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        fin[v[i]].push_back(i);
    }
    for(auto x:init){
        int cnte=0,cnto=0;
        for(auto y:x.second){
            cnte+=(y%2==0);
            cnto+=(y&1);
        }
        for(auto y:fin[x.first]){
            cnte-=(y%2==0);
            cnto-=(y&1);
        }
        if(cnte || cnto){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

}

int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
cin>>ttt;
while(ttt--){
    solve();
}
}




