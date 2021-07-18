
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define watch(x) cout << (#x) << " is " << (x) << endl
#define printVec(vec) {for(auto &x : vec) cout << x <<" "; cout << endl; }
#define printMap(mp) {for(auto &p : mp) cout << p.first <<" " <<p.second <<endl;}
#define hM 9999999900000001
#define inf 1e17

// ******l-r frequency nikalna hai to 26*n ka array bana0******
int gcd(int a,int b){
  if(a==0 || b==0){
    return (a+b);
  }
  return gcd(b,a%b);
}

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

const int facsz = 2;
int Fact[facsz];
int inFact[facsz];
void factorial(){
  Fact[0] =  inFact[0] = 1;
  for (int i = 1; i <facsz ; i++){
      Fact[i] = (Fact[i - 1] * i) % MOD;
      inFact[i] = modInverse(Fact[i],MOD);
    }
}

int __nCr(int n,int r,int mod){
  if(r > n || r < 0) return 0;
  return Fact[n] * inFact[n - r] % mod * inFact[r] % mod;
}
//BIT
int BIT[maxn];
void add(int x, int val) {while (x < N)BIT[x] += val, x += x & -x;}
int sum(int x) {return x ? BIT[x] + sum(x - (x & -x)) : 0;}

//ordered_set
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>



void solve(int T)
{
     int n;
     cin>>n;
     vector<int> arr(n);
     for(int i=0;i<n;i++){
          cin>>arr[i];
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
