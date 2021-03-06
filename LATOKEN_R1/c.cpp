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
const int MOD=1e9+7;
void solve(){
    int n;cin>>n;
    //map<int,bool> done;
    //map<int,int> one,two;
    vector<bool> done(n);
    vector<int> one(n),two(n);
    for(int i=0;i<n;i++){
        int x;cin>>x,--x;
        one[x]=i;
    }
    for(int i=0;i<n;i++){
        int x;cin>>x,--x;
        two[i]=x;
    }
    int cycle=0;
    for(int i=0;i<n;i++){
        if(!done[i]){
            done[i]=true;
            int st=i;
            while(two[one[st]]!=i){
                done[two[one[st]]]=true;
                st=two[one[st]];
                // 1 2 
                // 2 1
            }
            ++cycle;
        }
    }
    cout<<bp(2,cycle,MOD)<<"\n";
}
int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
cin>>ttt;
while(ttt--){
    solve();
}
}




