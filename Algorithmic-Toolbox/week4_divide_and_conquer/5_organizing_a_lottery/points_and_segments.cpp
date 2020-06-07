#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> fast_count_segments(vector<ll> starts, vector<ll> ends, vector<ll> points) {
  vector<ll> cnt(points.size());
  //write your code here
  map<ll, ll> mp;
  for(ll i=0; i<starts.size(); i++){
    mp[starts[i]] += 1;
    mp[ends[i]+1] += -1;
  }
  sort(points.begin(), points.end());
  vector<ll> pre(mp.size(),0);

  map<ll,ll>::iterator ip = mp.begin();
  map<ll,ll>::iterator it=mp.begin();
  ++it;
  for( ; it!=mp.end(); ++it, ++ip){

        it->second += ip->second;
  }
/*
  for(map<ll,ll>::iterator it=mp.begin(); it!=mp.end(); ++it)
  {
      cout<<it->first<<" "<<it->second<<endl;
  }
*/

  for(ll i=0; i<points.size(); i++){
    map<ll,ll>::iterator it = mp.upper_bound(points[i]);
    if(it!=mp.end()){
     --it;
    cnt[i] = it->second;
    }
    else
        cnt[i] = 0;
  }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  ll n, m;
  std::cin >> n >> m;
    vector<ll> starts(n) ,ends(n);
  for (ll i = 0; i < n; i++) {
    cin >> starts[i] >> ends[i];
  }

  vector<ll> points(m);
  for (ll i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<ll> cnt = fast_count_segments(starts, ends , points);
  for (ll i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}

/*input:
5 3
0 3
1 4
4 7
5 6
9 10
2 3 4
*/
