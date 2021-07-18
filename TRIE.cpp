#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007
struct Node{
  bool isEnd;
  Node* children[26];

  Node(){
    isEnd = false;
    fill(children,children+26,nullptr);
  }
};
struct Trie{
  Node *root;

  Trie(){
    root = new Node();
  }

  void addWord(string word){
    Node *temp = root;
    for(int i=0;i<word.size();i++){
      if(temp->children[word[i]-'a'] == nullptr){
        temp->children[word[i]-'a'] = new Node();
      }
      temp = temp->children[word[i]-'a'];
    }
    temp->isEnd = true;
  }

  bool search(string word){
    Node* temp = root;
    for(int i=0;i<word.size();i++){
      if(temp->children[word[i]-'a'] == nullptr){
        return false;
      }
      temp = temp->children[word[i]-'a'];
    }
    return temp->isEnd;
  }

};

void solve(int T)
{
  Trie t;
  t.addWord("apple");
  t.addWord("ape");
  cout<<t.search("apple")<<endl;
  cout<<t.search("shakir")<<endl;
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
