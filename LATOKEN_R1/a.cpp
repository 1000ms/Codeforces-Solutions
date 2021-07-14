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
bool isvaild(vector<vector<char>> &check,vector<vector<char>> &v){
    for(int i=0;i<(int)v.size();i++){
        for(int j=0;j<(int)v[0].size();j++){
            if(v[i][j]=='.') continue;
            if(v[i][j]!=check[i][j]) return false;
        }
    }
    return true;
}
char flip(char &c){
    if(c=='R') return 'W';
    return 'R';
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            v[i][j]=s[j];
        }
    }
    vector<vector<char>> check1(n,vector<char>(m));
    vector<vector<char>> check2(n,vector<char>(m));
    char c1='W',c2='R';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0){
                check1[i][j]=c1;
                check2[i][j]=c2;
                c1=flip(c1),c2=flip(c2);
            }
            else{
                check1[i][j]=flip(check1[i-1][j]);
                check2[i][j]=flip(check2[i-1][j]);
            }
        }
    }
    if(isvaild(check1,v)){
        cout<<"YES\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<check1[i][j];
            }
            cout<<"\n";
        }
        return;
    }
    if(isvaild(check2,v)){
        cout<<"YES\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<check2[i][j];
            }
            cout<<"\n";
        }
        return;
    }
    cout<<"NO\n";
}
int main(){
cin.tie(0);ios_base::sync_with_stdio(0);
int ttt=1;
cin>>ttt;
while(ttt--){
    solve();
}
}




