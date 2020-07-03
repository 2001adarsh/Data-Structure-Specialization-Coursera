#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl  "\n"

class Graph
{
  map<ll , list<ll> > l;  //adj list
public:
  map<ll, bool> visited; //visited

  void addEdge(ll x, ll y) {
    l[x].push_back(y);
    l[y].push_back(x);
  }

  void dfs(ll node) {
    visited[node] = true;
    for (auto nbr : l[node]) {
      if (!visited[nbr]) {
        dfs(nbr);
      }
    }
  }
};

int main()
{ ios_base::sync_with_stdio(false);
  cin.tie(NULL);



  ll n, m;
  cin >> n >> m;
  Graph g;

  for (ll i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    g.addEdge(x, y);
  }
  ll cnt = 0;
  for (ll i = 1; i <= n; i++) {
    if (!g.visited[i]) {
      cnt++;
      g.dfs(i);
    }
  }
  cout << cnt;

  return 0;
}