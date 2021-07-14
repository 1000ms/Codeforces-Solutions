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
const int MAXN=100005;
bool is_prime[MAXN+1];
vector<int> prime_list;
void sieve(){
    memset(is_prime,1,sizeof(is_prime));
    for(int i=2;i*i<=MAXN;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=MAXN;j+=i){
                is_prime[j]=false;
            }
        }
    }
    for(int i=2;i<=MAXN;i++){
        if(is_prime[i]){
            prime_list.push_back(i);
        }
    }
}

vector<int> fact(ll val){
    vector<int> fact;
    for(int i=0;i<(int)prime_list.size() && prime_list[i]*prime_list[i]<=val;i++){
        while(val%prime_list[i]==0){
            val/=prime_list[i];
            fact.push_back(prime_list[i]);
        }
    }
    if(val!=1) fact.push_back(val);
    return fact;
}

void solve(){
    ll a,b,k;cin>>a>>b>>k;
    if(k==1){
        if((a%b!=0 && b%a!=0) || a==b) cout<<"NO\n";
        else cout<<"YES\n";
        return;
    }
    vector<int> fact_a=fact(a);
    vector<int> fact_b=fact(b);
    if(k<=(int)fact_a.size()+(int)fact_b.size()) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
sieve();
cin>>ttt;
while(ttt--){
    solve();
}
}




