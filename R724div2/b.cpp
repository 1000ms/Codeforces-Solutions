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
    string s;
    cin>>s;
    vector<string> lex={""};
    while(true){
        vector<string> done;
        for(auto str:lex){
            for(int i=0;i<26;i++){
                string temp=str+(char)('a'+i);
                if(s.find(temp)==string::npos){
                    cout<<temp<<"\n";
                    return;
                }
                done.push_back(temp);
            }
        }
        lex=done;
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




