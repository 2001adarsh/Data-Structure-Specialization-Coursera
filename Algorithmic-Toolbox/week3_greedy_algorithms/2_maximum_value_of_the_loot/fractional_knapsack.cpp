#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  // write your code here
  vector< pair<double, int> > vec;
  for(int i=0; i<weights.size(); ++i) {
    vec.push_back(make_pair( (double)values[i]/weights[i] , weights[i] ));
  }
    sort(vec.begin(), vec.end(), greater<pair<double, int> >());

  for(int i=0; i<vec.size(); ++i){
    if(capacity <=0)
        break;
    int a = min(vec[i].second , capacity);
    capacity = capacity - a;
    value += (double)a * (double)vec[i].first;
  }
  return (double)value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
