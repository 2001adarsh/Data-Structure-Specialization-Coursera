#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd_naive(ll a, ll b) {
  ll current_gcd = 1;
  for (ll d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

// a = a' + bq  -> a/d only when a'/d and b/d;
ll gcd_fast(ll a, ll b) {
    if(b == 0)
        return a;
    gcd_fast(b, a%b);
}

void test(){
    ll a = 3;
    ll b = 5;
    for(int n = 0; n < 100; ++n) {
        assert( gcd_fast(a+n, b+n) == gcd_naive(a+n, b+n));
    }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  test();
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
