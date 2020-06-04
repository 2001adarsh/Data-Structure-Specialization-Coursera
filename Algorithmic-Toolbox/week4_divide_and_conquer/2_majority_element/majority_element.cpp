#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  cout<<left<<' '<<right<<endl;
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
}

vector<int> merge(vector<int> a, vector<int> b){
    int m = a.size();
    int n = b.size();
    vector<int> res(n+m , 0);
    int i=0, j=0,x=-1;
    while(i<m && j<n){
        ++x;
        if(a[i] <= b[j]){
            res[x] = a[i];
            i++;
        } else{
            res[x]= b[j];
            j++;
        }
    }
    // If a[i] is still remaining
    while(i<m){
        ++x;
        res[x] = a[i];
        i++;
    }
    //similarly for b
    while(j<n){
        ++x;
        res[x] = b[j];
        j++;
    }
    return res;
}

vector<int> mergesort(vector<int>& a) {
    if(a.size()==1){
        return a;
    }
    int mid =  (int)((a.size())/2);
    vector<int> b(a.begin(), a.begin()+mid);
    b = mergesort(b);
    vector<int> c(a.begin()+mid, a.begin()+a.size());
    c = mergesort(c);
    return merge(b, c);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  if(n ==1){
    cout<<"1";
  }
  else{
  vector<int> res = mergesort(a);
  int count = 1, ans =0;
  for(int i=0; i<res.size()-1; ++i){
    if(res[i] == res[i+1]){
        count++;
    }
    else {
        ans = max(count, ans);
        count =1;
    }
  }
    if(ans > n/2)
        cout<<"1";
    else cout<<"0";
  }
  //std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
