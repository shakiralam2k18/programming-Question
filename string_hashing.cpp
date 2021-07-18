#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007
const int p = 31;
const int m = 1e9 + 9;
const int sz = 1e6+5;
vector<long long> p_pow(sz);
vector<long long> h(sz, 0);
int compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    int hash_value = 0;
    int p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
void precompute_hash(string const& s) {
    int n = s.size();
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    // int cnt = 0;
    // for (int l = 1; l <= n; l++) {
    //     set<long long> hs;
    //     for (int i = 0; i <= n - l; i++) {
    //         long long cur_h = (h[i + l] + m - h[i]) % m;
    //         cur_h = (cur_h * p_pow[n-i-1]) % m;
    //         hs.insert(cur_h);
    //     }
    //     cnt += hs.size();
    // }
    // //return cnt;
}
bool check(int n, int l){
  int hash1 = (h[l]+m - h[0])%m;
  hash1 = (hash1%m * p_pow[n-1]%m)%m;
  int hash2 = (h[n]+m - h[n-l])%m;
  hash2 = (hash2%m * p_pow[l-1]%m)%m;
  if(hash1!=hash2){
    return false;
  }
  for (int i = 1; i < n-l; i++) {
          int cur_h = (h[i + l] + m - h[i]) % m;
          cur_h = (cur_h * p_pow[n-i-1]) % m;
          if(cur_h == hash1){
            return true;
          }
      }
  return false;
}

void solve(int T)
{
  string s;
  cin>>s;
  precompute_hash(s);
  int l = (int)s.size()-1;
  while(l--){
    //cout<<l<<endl;
    if(l!=0 && check(s.size(),l)){
      cout<<s.substr(0,l)<<endl;
      return;
    }
  }
  cout<<"Just a legend"<<endl;
  return;
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
