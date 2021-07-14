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

struct segtree{
    int size;
    vector<int> values;
    void init(int n){
        size=1;
        while(size<n) size*=2;
        values.assign(2*size,0);
    }
     
    void build(vector<int> &a,int x,int lx,int rx){
       if(lx+1==rx){
           if(lx<(int)a.size()){
               values[x]=a[lx];
           }
           return;
       }
       int m=(lx+rx)/2;
       build(a,2*x+1,lx,m);
       build(a,2*x+2,m,rx);
       values[x]=__gcd(values[2*x+1],values[2*x+2]);
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    void set(int i,int v,int x,int lx,int rx){
        if(rx-lx==1){
                values[x]=v;
            return;
        }
        int m=(lx+rx)/2;
        if(i<m) set(i,v,2*x+1,lx,m);
        else set(i,v,2*x+2,m,rx);
        values[x]=__gcd(values[2*x+1],values[2*x+2]);
    }
    void set(int i,int v){
        set(i,v,0,0,size);
    }
    int gcd(int l,int r,int x,int lx,int rx){
        if(lx>=l && rx<=r){
            return values[x];
        }
        if(rx<=l || lx>=r){
            return 0;
        }
        int m=(lx+rx)/2;
        int s1=gcd(l,r,2*x+1,lx,m);
        int s2=gcd(l,r,2*x+2,m,rx);
        return __gcd(s1,s2);
    }
    int gcd(int l,int r){
        return gcd(l,r,0,0,size);
    }
 
};


void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    segtree st;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++) v.push_back(v[i]);
    st.init(2*n);
    st.build(v);
    int l=-1,r=n+1;
    while(l+1<r){
        int m=(l+r)/2;
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(st.gcd(i,i+m+1));
        }
        if((int)s.size()==1) r=m;
        else l=m;
    }
    cout<<r<<"\n";
}

int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
cin>>ttt;
while(ttt--){
    solve();
}
}




