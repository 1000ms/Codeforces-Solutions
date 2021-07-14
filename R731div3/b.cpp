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
    string s;cin>>s;
    map<char,int> m;
    int n=(int)s.size();
    for(int i=0;i<n;i++){
        if(m.count(s[i])){
            cout<<"NO\n";
            return;
        }
        m[s[i]]=i;
    }
    int cnt=1;
    if(!m.count('a')){
        cout<<"NO\n";
        return;
    }
    int left=m['a']-1,right=m['a']+1;
    for(char c='b';c<='z' && cnt<n;c++){
        if(!m.count(c)){
            cout<<"NO\n";
            return;
        }
        if(m[c]==left) left-=1;
        else if(m[c]==right) right+=1;
        else{
            cout<<"NO\n";
            return;
        }
        ++cnt;
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




