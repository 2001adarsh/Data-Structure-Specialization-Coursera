#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll get_fibonacci_last_digit_naive(ll n) {
    if (n <= 1)
        return n;

    ll previous = 0;
    ll current  = 1;

    for (ll i = 0; i < n - 1; ++i) {
        ll tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
    return current % 10;
}

ll get_fibonacci_last_digit_fast(ll n) {
    if(n <= 1)
        return n;
    vector<ll> f(n+1, 0);
    f[0] = 0;
    f[1] = 1;

    for(ll i=2; i<= n; ++i) {
       f[i] = ((f[i-1] %10) + (f[i-2] %10) ) %10;
    }
    return f[n];
}

void test(){
    ll c1 = get_fibonacci_last_digit_naive(10);
    ll c2 = get_fibonacci_last_digit_fast(10);
    assert(c1 == c2);

    for(ll n=2; n< 20; ++n){
        assert(get_fibonacci_last_digit_fast(n) == get_fibonacci_last_digit_naive(n));
    }
}

int main() {
    ll n;
    std::cin >> n;
  //  test();
    ll c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
