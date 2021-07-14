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
string x;
cin>>x;
int val=stoi(x);
int n=(int)x.size();
if(n==1){
    cout<<"NO\n";
    return;
}
for(ll i=11;i<1e9;){
    if((ll)val%i==0) {
        cout<<"YES\n";
        return;
    }
    string temp=to_string(i);
    temp+='1';
    i=stoi(temp);
}
for(int i=1;i<n-1;i++){
    if(x[i]<x[i-1]) {
        cout<<"NO\n";
        return;
    }
}
if(x[n-1]!=x[n-2]){
    if(x[n-1]=='0' && n!=2){
        cout<<"YES\n";
        return;
    }
    else{
        cout<<"NO\n";
        return;
    }
}
else{
    cout<<"YES\n";
    return;
}
}
int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
cin>>ttt;
while(ttt--){
    solve();
}
}




