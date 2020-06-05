#include <iostream>
#include <vector>
using namespace std;
using std::vector;

typedef long long ll;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here


  return number_of_inversions;
}

ll ans =0;

vector<int> merge(vector<int>&a, vector<int>& b) {
    vector<int> res;
    int i=0, j=0;
    while(i<a.size() && j<b.size()) {
        if(a[i] <= b[j]){
            res.push_back(a[i]);
            i++;
        } else {
            ans += (a.size()  -i);
            res.push_back(b[j]);
            j++;
        }
    }
    while(i<a.size()){
        res.push_back(a[i]);
        i++;
    }
    while(j<b.size()){
        res.push_back(b[j]);
        j++;
    }
    return res;
}

vector<int> mergesort(vector<int>& a){
    if(a.size() <=1)
        return a;
    int mid = (int)(a.size()-1)/2;
    vector<int> b(a.begin(), a.begin()+mid+1);
    b = mergesort(b);
    vector<int> c(a.begin()+mid+1, a.begin()+a.size());
    c = mergesort(c);
    return merge(b,c);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }

  vector<int> res = mergesort(a);
/*
  for(size_t i=0; i<res.size(); i++) {
    cout<<res[i]<<" ";
  }
  cout<<endl;
  */
  cout<<ans;
  //vector<int> b(a.size());
  //std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
