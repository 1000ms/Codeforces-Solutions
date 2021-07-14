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
int n,m;
cin>>n>>m;
string s;
cin>>s;
int l=0,r=n-1;
while(s[l]=='0') l++;
while(s[r]=='0') r--;
if(l>r){
    cout<<s<<"\n";
    return;
}
for(int i=l;i>=max(0,l-m);i--) {
    s[i]='1';
}
for(int i=r;i<=min(n-1,r+m);i++) s[i]='1';
vector<int> range;
for(int i=l;i<=r;i++){
    if(s[i]=='1') range.push_back(i);
}
for(int i=1;i<(int)range.size();i++){
    int left=range[i-1]+1,right=range[i]-1;
    int me=m;
    while(left<right){
        if(m==0) break;
        s[left++]='1';
        s[right--]='1';
        m--;
    }
}
cout<<s<<"\n";
}
int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
cin>>ttt;
while(ttt--){
    solve();
}
}




