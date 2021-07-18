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

map<int, vi> mp;
for (int i = 0; i < n ; i++)
{
     vector<vector<int> > vs;
     for (int j = i + 1; j < n; j++)
     {
          int sum = v[j] + v[i];
          int rq = (s - sum);
          if (mp.count(rq))
          {
               cout << mp[rq][0] << " " << mp[rq][1] << " " << (i + 1) << " " << (j + 1) << endl;
               return;
          }
     }
     for (int j = i - 1; j >= 0; j--)
     {
          int sum = (v[i] + v[j]);
          mp[sum] = {i + 1, j + 1};
     }

}



const int psz = 20;
int prime[psz];
void sieve(){
  prime[0]= prime[1] =1;
  for(int i=2;i<psz;i++){
    if(!prime[i]){
      for(int j=2*i;j<psz;j+=i)
            prime[j]++;
	}
  }
}

//Graph starting.......

//dfs
bool dfs(int curr, int end){
     if(curr == end){
          return true;
     }
     visited[curr] = true;
     bool found = false;
     for(int adjacent : list[curr]){
          if(visited[adjacent]){
               continue;
          }
          if(dfs(adjacent,end)){
               found = true;
          }
     }
     return found;
}



// bfs   && sssp from bfs for unweighted graph
void bfs(int source){
     queue<int> q;
     for(int i=0;i<distance.size();i++){
          distance[i] = INT_MAX;
     }
     q.push_back(source);
     distance[source] = 0;
     visited[source] = true;
     while(!q.empty()){
          int curr = q.front();
          q.pop();
          for(auto adjacent : list[curr]){
               if(visited[adjacent]){
                    continue;
               }
               q.push(adjacent);
               visited[adjacent] = true;
               distance[adjacent] = distance[curr]+1;
          }
     }
}

// dijkastra... Algorithm
int visited[1000];

vector<int> dijkastra(vector<vector<int>>&adj, int source){
     vector<int> dis(1000,1e17);
     set<vector<int>> s;
     s.insert({0,source});
     dis[source] = 0;
     while(!s.empty()){
          auto it = s.begin();
          int u = (*it)[0];
          s.erase(it);

          for(auto nbr: adj[u]){
               int v = nbr.first, w = nbr.second;
               if(dis[v] > dis[u]+w){
                    s.erase({dis[v],v});
                    dis[v] = dis[u]+w;
                    s.insert({dis[v],v});
               }
          }
     }
}
