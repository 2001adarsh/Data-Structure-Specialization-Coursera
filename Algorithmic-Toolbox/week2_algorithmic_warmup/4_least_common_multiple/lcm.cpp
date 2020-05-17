#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long lcm_naive(ll a, ll b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

ll gcd_fast(ll a, ll b) {
    if(b == 0)
        return a;
    return gcd_fast(b, a%b);
}

ll lcm_fast(ll a, ll b) {
    if(b == 0 || a == 0)
        return 0;
    ll x = gcd_fast(a, b);
    return (a * b) / x ;
}

void test() {
    ll a = 6;
    ll b = 12;
    for(ll n = 89; n < 2403 ; ++n) {
        assert(lcm_fast(a+n, b+n) == lcm_naive(a+n, b+n));
    }
}

int main() {
  ll a, b;
  std::cin >> a >> b;
 // test();
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
