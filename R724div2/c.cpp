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
    string s;cin>>s;
    map<pair<int,int>,int> m;
    int d=0,k=0;
    for(char c:s){
        d+=c=='D';
        k+=c=='K';
        int g=__gcd(d,k);
        cout<<++m[make_pair(d/g,k/g)]<<" ";
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




