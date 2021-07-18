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
void LPS(string word, int lps[]){
    int n=word.size();
    int s=0, e=1;
    lps[s]=0;
    while(e<n){
      if(word[s]==word[e])
          lps[e++] = ++s;
      else{
          if(s!=0)
            s=lps[s-1];
          else
            lps[e++]=0;
      }
    }
}

void search(string text, string word, int lps[],vector<int>&index){
    int w=0, t=0;
    while(t < text.length() && w < word.size()){
      if(word[w] == text[t]){
          w++, t++;
          //cout<<w<<"*"<<t<<endl;
          if(w == word.size()){
              //cout<<"found at "<< t-w <<endl;
              index.push_back(t-w);
              w=lps[w-1];
              //return true;
          }
        }
          else{
                if(w!=0)
                  w=lps[w-1];
                else
                  t++;
          }
      }
      //return false;
}




void solve(int T)
{
    string s="aaaa";
    vector<int> index;
    string str="a";
    int lps[4];
    LPS(str,lps);
    search(s,str,lps,index);
    for(int i=0;i<index.size();i++){
      cout<<index[i]<<" ";
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
