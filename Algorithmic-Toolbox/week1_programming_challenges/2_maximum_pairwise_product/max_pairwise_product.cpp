#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MaxPairwiseProduct(const std::vector<ll>& numbers) {
    ll max_product = 0;
    ll n = numbers.size();
    ll maximum = INT_MIN , secondmaximum = INT_MIN;
    ll idx = 0;
    for (ll first = 0; first < n; ++first) {
            if(maximum < numbers[first]){
            maximum = max( numbers[first], maximum);
            idx = first;
            }
        }
    for(ll second = 0; second < n; ++second){
        if( second != idx){
            secondmaximum = max(numbers[second], secondmaximum);
        }
    }
  //  cout << maximum << " "<< secondmaximum<<endl;
    max_product = maximum * secondmaximum;
    return max_product;
}

int main() {

    ll n;
    std::cin >> n;
    std::vector<ll> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;

}
