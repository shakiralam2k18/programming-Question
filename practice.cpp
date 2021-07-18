#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007

double exact(int a, int b){
  return (double)a/b;
}
int gcd(int a,int b){
  if(a==0 || b==0){
    return (a+b);
  }
  return gcd(b,a%b);
}
//int extended_euclidean(int a, int b)
int fastExpo(int a,int n,int mod){
  int result = 1;
  while ( n > 0){
    if ( n&1 )
      result = (result*a)%mod;
    a=(a*a)%mod;
    n>>=1;
  }
  return result;
}

int modInverse(int n,int mod){
  return fastExpo(n,mod-2,mod);
}

vector<int> factorial(int n){
  std::vector<int> fac(n+2,0);
  fac[0] = 1;
  for (int i = 1; i <= n; i++)
      fac[i] = (fac[i - 1] * i) % MOD;

  return fac;
}

int __nCr(int n,int r, vector<int>& Fact,int mod){
    int ans= (((Fact[n] * modInverse(Fact[r],mod))%mod)*modInverse(Fact[n-r],mod))%mod;
    return ans;
}
vector<char> vec;
bool check(vector<string> v,int index,int a, int b, int c, vector<char>&s){
  if(a<0 || b<0 || c<0){
    return false;
  }
  if(index>=v.size()){
    vec = s;
    return true;
  }
  bool ans1,ans2;
  if(v[index]=="AB"){
    s.push_back('B');
    ans1 = check(v,index+1,a-1,b+1,c,s);
    s.pop_back();
    s.push_back('A');
    ans2 = check(v,index+1,a+1,b-1,c,s);
    s.pop_back();
  }
  if(v[index]=="BC"){
    s.push_back('B');
    ans1 = check(v,index+1,a,b+1,c-1,s);
    s.pop_back();
    s.push_back('C');
    ans2 = check(v,index+1,a,b-1,c+1,s);
    s.pop_back();
  }
  if(v[index]=="AC"){
    s.push_back('C');
    ans1 = check(v,index+1,a-1,b,c+1,s);
    s.pop_back();
    s.push_back('A');
    ans2 = check(v,index+1,a+1,b,c-1,s);
    s.pop_back();
  }
  if(ans1 || ans2){
    return true;
  }
  return false;

}
void solve(int T)
{
  int n,a,b,c;
  cin>>n>>a>>b>>c;
  vector<string> v;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    v.push_back(s);
  }
  vector<char> s;
  bool ans = check(v,0,a,b,c,s);
  if(ans){
    cout<<"Yes"<<endl;
    for(int i=0;i<vec.size();i++){
      cout<<vec[i]<<endl;
    }
  }
  else{
    cout<<"No"<<endl;
  }
} 

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("error.out", "w", stderr);
    freopen("outputf.out", "w", stdout);
#endif

    int T = 1;
    //cin >> T;
    for (int t=1;t<=T; t++) {
        solve(t);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
