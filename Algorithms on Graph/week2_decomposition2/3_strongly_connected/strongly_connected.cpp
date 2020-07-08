#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl  "\n"

const int N = 100005;

std::vector<ll> v[N];
bool vis[N] = {false};

void dfs(ll node) {
  vis[node] = true;
  for (auto nbr : v[node]) {
    if (!vis[nbr])
      dfs(nbr);
  }
}

int main()
{ ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n, m;
  cin >> n >> m;
  for (ll i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    v[x].push_back(y);
  }

  ll cnt = 0;
  for (ll i = 1; i <= n; i++) {
    if (!vis[i]) {
      cnt++;
      dfs(i);
    }
  }
  cout << cnt;
  return 0;
}
/*#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj);
}
*/