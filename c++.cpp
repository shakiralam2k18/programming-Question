#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(x) x.begin(),x.end()
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
vector<int> sieve(int n){
  vector<int> v(n+2,0);
	vector<int> primes;
  //primes.push_back(1);
  n++;
  v[0]=1;
  for(int i=2;i<n;i++){
    if(!v[i]){
			primes.push_back(i);
      for(int j=2*i;j<n;j+=i)
        v[j]++;
			}
  }
  return primes;
}
void solve(int T)
{
    int n;
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
