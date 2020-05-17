#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
ll get_fibonacci_huge_fast(ll n, ll m) {
    if(n <=1)
        return n;

    vector<ll> f;
    f.push_back(0);
    f.push_back(1);
    ll count =2;
    while(true) {
        ll last = f[f.size()-1] % m;
        ll secondLast = f[f.size()-2] % m;
        f.push_back((last + secondLast)%m);
        if(last == 0 && (f[f.size()-1]%m) ==1){
            count--;
            break;
        }
     //   cout << f.size()<<endl;
        count++;
    }
    ll res = n%count;
    return f[res];
}

void test() {
    ll m = 4;
    for(ll i=20; i<34; ++i) {
        assert(get_fibonacci_huge_fast(i, m) == (get_fibonacci_huge_naive(i,m)));
    }
}

int main() {
    long long n, m;
    std::cin >> n >> m;
   // std::cout << get_fibonacci_huge_fast(n, m) << '\n';
   // test();
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
