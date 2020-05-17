#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using std::vector;
typedef long long ll;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

ll get_sum_till(ll n) {
    if(n <= 1)
        return n;
    ll count =2;
    vector<ll> f;
    f.push_back(0);
    f.push_back(1);
    while(true) {
        ll last = f[f.size() - 1] % 10;
        ll secondLast = f[f.size() - 2] % 10;
        f.push_back((last + secondLast)%10);
        if(last==0 && (f[f.size()-1]%10) ==1) {
            count--;
            break;
        }
        count++;
    }
    return f[n%count];
}

ll get_fibonacci_partial_sum_fast(ll from, ll to) {
    ll sum =0;
    ll x = get_sum_till(to+2);
    ll y = get_sum_till(from+1);
   // cout<<x << " "<<y;
    if(x < y){
        sum = (x+10) - y;
    }else{
        sum = x - y;
    }
    return sum;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
