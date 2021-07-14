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
priority_queue<ll,vector<ll>,greater<ll>> pq;
ll s=0;
for(int i=0;i<n;i++){
    ll x;
    cin>>x;
    s+=x;
    pq.push(x);
    while(s<0){
        s-=pq.top();
        pq.pop();
    }
}
cout<<(int)pq.size();
}
int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
//cin>>ttt;
while(ttt--){
    solve();
}
}




