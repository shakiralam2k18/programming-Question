
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
//    NOTES
// SSSP -> Dijkastra(greedy Algorithm)  worst wala (O(V*V+E)), best wala set se
// sssp ->  Belman ford(negative cycle)
//  Time complexity of topoSort = O(V+E);
int n,m;
vector<vector<int>> AdjList;
vector<int> visited;

void bfs(int source){
     queue<int> q;
     q.push(source);
     visited[source] =1;
     while(!q.empty()){
          int a = q.front();
          cout<<a<<"->";
          q.pop();
          for(auto adj: AdjList[a]){
               if(visited[adj]) continue;
               q.push(adj);
               visited[adj] = 1;
          }
     }
}

vector<int> topo_bfs(){
     // kanh's Algo
     vector<int> ans;
     int in[n+1] ={0};
     for(int i=1;i<=n;i++){
          for(auto j: AdjList[i]){
               in[j]++;
          }
     }
     queue<int> q;
     for(int i=1;i<=n;i++){
          if(in[i] == 0){
               q.push(i);
          }
     }
     while(!q.empty()){
          int t = q.front();
          //cout<<t<<endl;
          ans.push_back(t);
          q.pop();
          for(auto adj: AdjList[t]){
               in[adj]--;
               if(in[adj] == 0)q.push(adj);
          }
     }
     if(ans.size() < n){
          return {-1};
     }
     return ans;
}


bool topoSort_dfs(int u,vector<int>&ans){
     visited[u] = 1;
     for(auto adj: AdjList[u]){
          if(visited[adj] == 0){
               bool flag = topoSort_dfs(adj,ans);
               if(!flag) return false;
          }
          else if(visited[adj] == 1){
               return false;
          }
     }
     visited[u] = 2;
     ans.push_back(u);
     return true;
}

bool dfs(int u, vector<int>& ans){
     if(visited[u]) return visited[u] == 2;
     visited[u] = 1;
     for(auto v: AdjList[u]){
          if(visited[v] == 1){
               return false;
          }
          if(visited[v] == 0){
               bool can = dfs(v,ans);
               if(!can) return false;
          }
     }
     visited[u] = 2;
     ans.push_back(u);
     return true;
}



vector<int> topo_dfs(){
     vector<int> ans;
     for(int i=n;i>=1;i--){
          if(!visited[i]){
               dfs(i,ans);
          }
     }
     reverse(all(ans));
     return ans;
}

vector<int> dijkastra(vector<vector<pair<int,int>>>&adj, int source){
     vector<int> dis(n+3,1e17);
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

vector<int> bellman_ford(vector<vector<int>>& graph, int src, int vertex){
     vector<int> dis(vertex+1,INT_MAX);
     dis[src] = 0;
     for(int i=1;i<vertex;i++){
          for(auto edge: graph){
               if(dis[edge[0]] == INT_MAX) continue;
               dis[edge[1]] = min(dis[edge[1]],dis[edge[0]]+edge[2]);
          }
     }
     return dis;
}

int parent[1000];
int get_parent(int i){
     if(parent[i] == i) return i;
     return parent[i] = get_parent(parent[i]);
}
void Union(int a, int b){
     if(get_parent(a) == get_parent(b)) return;
     a = get_parent(a), b = get_parent(b);
     parent[a] = b;
}

int kruskal(vector<vector<int>>&graph){
     sort(all(graph));
     int ans= 0;
     for(int i=0;i<graph.size();i++){
          int w = graph[i][0], u= graph[i][1], v = graph[i][2];
          if(get_parent(u) != get_parent(v)){
               Union(u,v);
               ans += w;
          }
     }
     return ans;
}
void solve(int T)
{
     cin>>n>>m;
     // AdjList.resize(n+3);
     // visited.resize(n+3,0);
     // for(int i=0;i<m;i++){
     //      int x,y;
     //      cin>>x>>y;
     //      AdjList[x].push_back(y);
     //      AdjList[y].push_back(x);
     // }
     vector<vector<int>> graph;
     for(int i=0;i<m;i++){
          int u,v,w;
          cin>>u>>v>>w;
          graph.push_back({w,u,v});
          //graph.push_back({v,u,w});
     }
     for(int i=1;i<=n;i++){
          parent[i] = i;
     }
     int ans = kruskal(graph);
     cout<<ans<<endl;
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
