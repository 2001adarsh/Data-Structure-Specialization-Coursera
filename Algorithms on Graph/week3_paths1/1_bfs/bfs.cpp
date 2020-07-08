#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl 	"\n"

const int N = 100005;
vector<ll> v[N];

ll bfs(ll src, ll dest, ll n) {
	ll dis[N + 1] = {0};
	for (ll i = 1; i <= n; i++) {
		dis[i] = INT_MAX;
	}
	queue<ll> q;
	q.push(src);
	dis[src] = 0;

	while (!q.empty()) {
		ll node = q.front();
		q.pop();
		for (auto nbr : v[node]) {
			if (dis[nbr] == INT_MAX) {
				dis[nbr] = dis[node] + 1;
				q.push(nbr);
			}
		}
	}
	return (dis[dest] != INT_MAX) ? dis[dest] : -1;
}

int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	ll x, y;
	cin >> n >> m;
	for (ll i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin >> x >> y;
	cout << bfs(x, y, n);
	return 0;
}
