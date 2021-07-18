int helper(string s, string p, int size){
    unordered_map<char,int> map;
    for(int i=0;i<p.size();i++){
      map[p[i]]++;
    }
    for(int j=0;j<=s.size()-mid;j++){
      unordered_map<char,int>mymap;
      for(int i=j;i<size+j;i++){
        mymap[s[i]]++;
      }
      for(int i=0;i<p.size();i++){
        mymap[s[i]]--;
      }
      int flag=0;
      for(auto each:mymap){
        if(each.second<0){
          flag=1;
          break;
        }
      }
      if(flag==0){
        return size;
      }
    }

}

string smallestWindow (string s, string p){
    // Your code here
    vector<pair<int,int>> v;
    int start=p.size();
    int end=s.size();
    unordered_map<char,int>map;
    for(int k=0;k<p.size();k++){
            map[p[k]]++;
        }
    int flag;
    while(start<=end){
        int mid=(start+end)/2;
        int j=0,k=mid-1;
        unordered_map<char,int>mymap;
        for(int j=0;j<=s.size()-mid;j++){
            int i;
            for(i=j;i<mid+j;i++){
                mymap[s[i]]++;
            }
            for(int k=0;k<p.size();k++){
                mymap[s[k]]--;
            }
            flag=0;
            for(auto each: mymap){
                if(each.second<0){
                    flag=1;
                    cout<<flag<<'*';
                    break;
                }
            }
            if(flag==0){
              v.push_back({j,mid+j});
              end=mid-1;
              break;
            }
        }
        start=mid+1;

    }
    if(v.size()==0){
        return "";
    }
    int a=v[v.size()-1].first;
    int b=v[v.size()-1].second;
    string str="";
    for(int i=a;i<b;i++){
        str+=s[i];
    }
    return str;

}
