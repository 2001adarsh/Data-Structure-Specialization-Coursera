#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl 	"\n"

const int N = 100005;
vector<ll> v[N];
bool isCyclic = true;
bool vis[N] = { false };
bool recStack[N] = { false };

void dfs(ll node) {
	vis[node] = true;
	recStack[node] = true;

	for (auto nbr : v[node]) {
		if (!vis[nbr])
			dfs(nbr);
		else if (recStack[nbr])
			isCyclic = false;
	}

	recStack[node] = false;
}

int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	cin >> n >> m;
	for (ll i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		v[x].push_back(y); //directed
	}
	for (ll i = 1; i <= n; i++) {
		if (!vis[i])
			dfs(i);
	}
	cout << (!isCyclic);

	return 0;
}
/*#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  return 0;
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
  std::cout << acyclic(adj);
}
*/
