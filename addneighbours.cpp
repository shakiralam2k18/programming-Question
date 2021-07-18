#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define watch(x) cout << (#x) << " is " << (x) << endl
#define MOD 1000000007

int gcd(int a,int b){
  if(a==0 || b==0){
    return (a+b);
  }
  return gcd(b,a%b);
}

vector<int> sieve(int n){
  vector<int> v(n+2,0);
  n++;
  v[0]=1;
  for(int i=2;i*i<n;i++){
    if(!v[i])
      for(int j=2*i;j<n;j+=i)
        v[j]=i;
  }
  return v;
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

int __nCr(int n,int r, vector<int>& Fact,int mod){
    int ans= (((Fact[n] * modInverse(Fact[r],mod))%mod)
    *modInverse(Fact[n-r],mod))%mod;
    return ans;
}

class Triplet{
 public:
   int x;
   int y;
   int gcd;
};
Triplet extendedEuclid(int a,int b){
  if(b==0){
    Triplet obj;
    obj.x=1;
    obj.y=0;
    obj.gcd=a;
    return obj;
  }
  Triplet smallans = extendedEuclid(b,a%b);
  Triplet ans;
  ans.gcd=smallans.gcd;
  ans.x=smallans.y;
  ans.y= smallans.x-(a/b)*smallans.y;
  return ans;
}

///---------------------------------------------------------/

// int getsum(int arr,int n,int )

void solve(int T)
{

  int n;
  cin>> n;
  vector<int> arr(n);
  int sum=0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    sum+=arr[i];
  }
  vector<int> ops;
  ops.push_back(arr[0]);
  for(int i=1;i<n;i++){
    int last = ops.back();
    int curr =arr[i];
    // if(last>curr)
    //   swap(last,curr);
    int ans = max((curr/last)*last,1LL);
    ops.push_back(ans);
  }
  for(auto each: ops){
    cout << each << " ";
  }
cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("error.out", "w", stderr);
    freopen("outputf.out", "w", stdout);
#endif

    int T = 1;
    cin >> T;
    for (int t=1;t<=T; t++) {
        solve(t);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
