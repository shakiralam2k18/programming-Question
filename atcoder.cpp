#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007

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

void solve(int T)
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  if(n<=4){
    cout<<0<<endl;
    return;
  }
  int count1=0, count2=0, count3=0;
  if(n>=5){
    for(int i=0;i<=n-5;i++){
      if(arr[i]<arr[i+1] && arr[i+1]>arr[i+2] && arr[i+2]<arr[i+3] && arr[i+3]>arr[i+4]){
        count1++;
      }
      else if(arr[i]>arr[i+1] && arr[i+1]<arr[i+2] && arr[i+2]>arr[i+3] && arr[i+3]<arr[i+4]){
        count1++;
      }
    }
    for(int i=0;i<=n-4;i++){
      if(arr[i]<arr[i+1] && arr[i+1]>arr[i+2] && arr[i+2]<arr[i+3]){
        count2++;
      }
      else if(arr[i]>arr[i+1] && arr[i+1]<arr[i+2] && arr[i+2]>arr[i+3]){
        count2++;
      }
    }
    for(int i=0;i<=n-3;i++){
      if(arr[i]<arr[i+1] && arr[i+1]>arr[i+2]){
        count3++;
      }
      else if(arr[i]>arr[i+1] && arr[i+1]<arr[i+2]){
        count3++;
      }
    }
    cout<<count1<<" "<<count2<<" "<<count3<<endl;
    if(count1>0){
      cout<<count3-3<<endl;
      return;
    }
    if(count2>0){
      cout<<count3-2<<endl;
      return;
    }
    if(count3>0){
      cout<<count3-1<<endl;
      return;
    }
    else{
      cout<<0<<endl;
      return;
    }
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
    cin >> T;
    for (int t=1;t<=T; t++) {
        solve(t);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
