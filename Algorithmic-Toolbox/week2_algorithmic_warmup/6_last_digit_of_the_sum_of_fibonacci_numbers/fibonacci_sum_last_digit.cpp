#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

ll fibonacci_sum_fast(ll n) {
    if(n <= 1)
        return n;
    vector<ll> f;

    f.push_back(0);
    f.push_back(1);

    ll last ;
    ll secondLast ;
    ll count = 2;
    while(true) {
        last = f[f.size()-1] % 10;
        secondLast = f[f.size() -2] % 10;
        f.push_back( (last%10 + secondLast%10)%10 );
        if(last == 0 && f[f.size()-1] % 10 ==1){
            count--;
            break;
        }
        count++;
    }
    n = n+2;
    ll res = n % count;
    res = (f[res] -1) >= 0 ? (f[res] -1) : 9;
    return ( res );
}

void test(){
    for(ll n= 5; n<23; ++n){
        assert(fibonacci_sum_fast(n) == fibonacci_sum_naive(n));
    }
}

int main() {
    long long n = 0;
    std::cin >> n;
   // test();
    cout<<fibonacci_sum_fast(n)<<endl;
    return 0;
}
