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
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(auto &it:b) cin>>it;
    int sum=0;
    for(int i=0;i<n;i++){
        a[i]=a[i]-b[i];
        sum+=a[i];
    }
    if(sum!=0){
        cout<<-1<<"\n";
        return;
    }
    vector<pair<int,int>> pos,neg,ans;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]<0) neg.emplace_back(a[i],i);
        else if(a[i]>0) pos.emplace_back(a[i],i);
    }
    int l=0,r=0;
    while(l<(int)pos.size() && r<(int)neg.size()){
        cnt++;
        ans.emplace_back(pos[l].second+1,neg[r].second+1);
        pos[l].first-=1,neg[r].first+=1;
        if(pos[l].first==0) ++l;
        if(neg[r].first==0) ++r;
    }
    cout<<cnt<<"\n";
    for(auto x:ans) cout<<x.first<<" "<<x.second<<"\n";
}

int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
cin>>ttt;
for(int rep=1;rep<=ttt;rep++){
solve();
}
}


