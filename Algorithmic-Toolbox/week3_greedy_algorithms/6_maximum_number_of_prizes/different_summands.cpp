#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  vector<bool> flag(n, false);
  //write your code here
  int i=0;
  while(i <= n){
    i++;
    //cout<<n<<" ";
    if(flag[n-i] == true || n-i == i){
        summands.push_back(n);
        break;
    } else{
        n -= i;
        summands.push_back(i);
        flag[i]= true;
    }
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
