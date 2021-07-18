#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007

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
vector<int> primes;
void solve(int T)
{
    int d;
    cin>>d;

    int p1=0,p2=0;
    for(int i=0;i<primes.size();i++){
      //cout<<primes[i]<<" ";
      if(p1==0 && (primes[i]-1) >= d){
        p1 = primes[i];
        //cout<<p1<<" ";
      }
      if(p1!=0 && p2==0 && primes[i]-p1>=d){
        p2 = primes[i];
        //cout<<p2<<" ";
      }
      if(p1 && p2){
        cout<<p1*p2<<endl;
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
    primes = sieve(1000000);
    int T = 1;
    cin >> T;
    for (int t=1;t<=T; t++) {
        solve(t);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
