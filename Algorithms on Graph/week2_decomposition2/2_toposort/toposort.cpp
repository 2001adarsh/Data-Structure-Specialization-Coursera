#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl 	"\n"
const int N = 1000005;
std::vector<ll> v[N];
bool vis[N] = {false};
bool used[N] = {false};
stack<ll> order;

void dfs(ll node) {
	vis[node] = true;
	for (auto nbr : v[node]) {
		if (!vis[nbr]) {
			dfs(nbr);
		}
	}
	order.push(node);
}


int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	cin >> n >> m;
	for (ll i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}

	for (ll i = 1; i <= n; i++)
		if (!vis[i])
			dfs(i);

	while (!order.empty())
	{
		cout << order.top() << " ";
		order.pop();
	}

	return 0;
}

/*#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x) {
  //write your code here
}

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> used(adj.size(), 0);
  vector<int> order;
  //write your code here
  return order;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
*/
