#include <bits/stdc++.h>
using namespace std;


const int sz= 100000+9;
int sieve[100000+9];
bool seive[sz];

vector<int> sieve(int n){
  vector<int> v(n+2,0);
	vector<int> primes;
	primes.push_back(1);
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

void construct_seive(){
  fill(seive, seive+sz,true);
  seive[0]=false;
  seive[1]=false;
  for(int i=2*2;i<sz;i+=2){
    seive[i]=false;
  }
  for(int i=3;i*i<sz;i+=2){
    if(seive[i]){
      for(int j=i*i;j<sz;j+=i){
        seive[j]=false;
      }
    }
  }
}

void construct_sieve_primefactor(){
    sieve[0]=0;
    sieve[1]=1;
    for(int i=2;i<sz;i++){
        sieve[i]=i;
    }
    //sieve[2]=2;
    for(int i=2*2;i<sz;i+=2){
        sieve[i]=2;
    }
    for(int i=3;i*i<sz;i+=2){

        if(sieve[i]==i){
            for(int j=i*i;j<sz;j+=i){
                if(sieve[j]==j)
                    sieve[j]=i;
            }
        }
        //sieve[i]=1;
    }
}
int main() {

  #ifndef ONLINE_JUDGE
      freopen("input.in", "r", stdin);
      freopen("error.out", "w", stderr);
      freopen("outputf.out", "w", stdout);
  #endif

    int n;
    cin>>n;

    construct_sieve_primefactor();
    for(int i=2;i<=n+1;i++){
      if(sieve[i]==i){
        cout<<sieve[i]<<" ";
      }
    }



}
