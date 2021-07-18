#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(x) x.begin(),x.end()
#define MOD 1000000007

class Node{
public:
     char data;
     int cnt;
     unordered_map<char,Node*> children;
     bool terminal;
     Node(char d){
          data = d;
          cnt = 0;
          terminal = false;
     }
};
class Trie{
public:
     Node *root;
     Trie(){
          root = new Node('\0');
     }

     void insert(string word){
          Node*temp = root;
          for(int i=0;i<word.size();i++){
               if(temp->children.count(word[i]) == 0)
                    temp->children[word[i]] = new Node(word[i]);
               temp = temp->children[word[i]];
               temp->cnt++;
          }
          temp->terminal = true;
     }

     string search(string word){
          Node* temp = root;
          string s = "";
          for(int i=0;i<word.size();i++){
               if(temp->children.count(word[i]) == 0)
                    return "";
               temp = temp->children[word[i]];
               s+= word[i];
               if(temp->cnt == 1){
                    return s;
               }
          }
          return "";
     }
};

void solve(int T)
{
     vector<string> v;
     v.push_back("apple");
     v.push_back("No");
     v.push_back("Not");
     Trie t;
     for(int i=0;i<v.size();i++){
          t.insert(v[i]);
     }
     for(int i=0;i<v.size();i++){
          cout<<t.search(v[i])<<endl;
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
