
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define MAX_SIZE 101
int A[MAX_SIZE];

class StackUsingArray{
public:
     int arr[MAX_SIZE];
     int idx = -1;

     void push(int x){
          arr[++idx] = x;
     }
     void pop(){
          if(idx == -1){
               return;
          }
          idx--;
     }
     int top(){
          if(idx == -1){
               return -1;
          }
          return arr[idx];
     }
};

class Node{
     int data;
     Node* next;

     Node(int data){
          this->data = data;
     }
};

class Stack{
     Node 
}

void solve(int T)
{
     StackUsingArray st;
     st.push(1);
     st.push(2);
     cout<<st.top();
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
