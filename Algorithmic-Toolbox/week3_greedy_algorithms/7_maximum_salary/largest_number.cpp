#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
using std::vector;
using std::string;

bool sortby(const string &a, const string &b){
    return (a+b) > (b+a);
}

string largest_number(vector<string> a) {
  sort(a.begin(), a.end(), sortby);
  //write your code here
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
