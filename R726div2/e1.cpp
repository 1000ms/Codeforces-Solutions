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
    int n,k;cin>>n>>k;
    string s;cin>>s;
    set<int> len;
    for(int i=1;i*i<=k;i++){
        if(k%i==0){
            len.insert(k/i);
            len.insert(i);
        }
    }
    vector<string> pref;
    for(auto x:len){
        if(x>n) break;
        string temp=s.substr(0,x);
        string to_push="";
        for(int i=0;i<k/x;i++){
            to_push+=temp;
        }
        pref.push_back(to_push);
    }
    sort(pref.begin(),pref.end());
    cout<<pref[0];
}

int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
//cin>>ttt;
while(ttt--){
    solve();
}
}




