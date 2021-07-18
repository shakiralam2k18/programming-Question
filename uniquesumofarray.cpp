#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007



int add(int a, int b, int mod){
  int ans= (a%mod +0ll +b%mod)%mod;
  if(ans<0){
    return ans+mod;
  }
  return ans%mod;
}

int mult(int a, int b, int mod){
  int ans= ((a%mod)* 1ll * (b%mod))%mod;
  if(ans<0){
    return ans+mod;
  }
  return ans%mod;
}


int fastexpo(int b, int n, int mod){
  if(n==0){
    return 1;
  }
  if(n&1){
  int ans1=fastexpo(b,n-1,mod);
  return mult(b,ans1,mod);
  }
else{
    int ans2=fastexpo(b,n/2, mod);
    return mult(ans2,ans2,mod);
  }
}

int modInverse(int b,int mod){
  return fastexpo(b,mod-2,mod);
}

int divide(int a, int b, int mod){
  int ans =mult(a,modInverse(b,mod),mod);
  if(ans<0){
    ans+=mod;
  }
  return ans;
}

void fact(int arr[], int n, int mod){
  arr[0]=arr[1]=1;
  for(int i=2;i<n;i++){
    arr[i]=mult(i,arr[i-1],mod);
  }
}

int gcd(int a,int b){
  if(a==0 || b==0){
    return (a+b);
  }
  return gcd(b,a%b);
}
int x,y;
int gcd_to_find_x_y(int a,int b){
  if(b==0){
    x=1,y=0;
    return a;
  }
  int x1, y1;
  int t=gcd_to_find_x_y(b,a%b);
  x1=x, y1=y;
  x=y1;
  y=x1-(a/b)*y1;
  return t;
}
vector<int> sieve(int n){
  vector<int> v(n+2,0);
  n++;
  v[0]=1;
  for(int i=2;i*i<n;i++){
    if(!v[i])
      for(int j=2*i;j<n;j++)
        v[j]++;
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
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
set<vector<int>> myset;
void unique_sum(vector<int> & arr,int i,int sum,vector<int> output){
  if(sum==0){
    myset.insert(output);
    return;
  }
  if(i<0){
    return;
  }

  unique_sum(arr,i-1,sum,output);
  output.push_back(arr[i]);
  unique_sum(arr,i-1,sum-arr[i],output);
  output.pop_back();
}



/*------------------------------------------*/

void solve(int T)
{
  int n;
  cin>>n;
  vector<int> arr;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    arr.push_back(x);
  }
  int sum;
  cin>>sum;
  vector<int> output;
  sort(arr.begin(),arr.end());
  unique_sum(arr,arr.size()-1,sum,output);
  for(auto each: myset){
    //vetor<int> v =each;
    for(int i=0;i<each.size();i++){
      cout<<each[i]<<" ";
    }
    cout<<endl;
  }
  myset.clear();
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
