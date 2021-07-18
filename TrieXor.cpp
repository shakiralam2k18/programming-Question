
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(x) x.begin(),x.end()
#define MOD 1000000007

class Node{
public:
     Node* left; // 0
     Node* right; // 1
     Node(){
          left = right = nullptr;
     }
};
class Trie{
public:
     Node* root;
     Trie(){
          root = new Node();
     }

     // insert
     void insert(int val){
          Node* temp = root;
          for(int i=31;i>=0;i--){
               int bit = (1<<i)&val;
               if(bit == 0){
                    if(temp->left == nullptr){
                         temp->left = new Node();
                    }
                    temp = temp->left;
               }
               else{
                    if(temp->right == nullptr){
                         temp->right = new Node();
                    }
                    temp = temp->right;
               }
          }
     }
     // max Xor of pair
     int maXor(int val){
          Node* temp = root;
          int ans = 0;
          for(int i=31;i>=0;i--){
               int bit = (1<<i)&val;
               if(bit == 0){
                    if(temp->right != nullptr){
                         ans += (1<<i);
                         temp = temp->right;
                    }
                    else
                         temp = temp->left;
               }
               else{
                    if(temp->left != nullptr){
                         ans += (1<<i);
                         temp = temp->left;
                    }
                    else
                         temp = temp->right;
               }
          }
          return ans;
     }
};

void solve(int T)
{
     int arr[] = {3,10,5,25,2,8};
     Trie t;
     for(int i=0;i<=5;i++){
          t.insert(arr[i]);
     }
     int ans = 0;
     for(int i=0;i<=5;i++){
          ans = max(ans,t.maXor(arr[i]));
     }
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
