#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl 	"\n"

class Graph
{
	int V;
	vector<pair<int, int> > *gr;
public:
	Graph(int V) {
		this->V = V;
		gr = new vector<pair<int, int> >[V];
	}

	void addEdge(int x, int y, int w) {
		gr[x].push_back({y, w});
		//gr[y].push_back({x,w});
	}

	int dijkstra(int src, int dest) {
		vector<int> dist(V, INT_MAX);
		set<pair<int, int> > st;
		dist[src] = 0;
		st.insert({dist[src], src});

		while (!st.empty()) {
			auto best = *(st.begin());
			st.erase(st.begin());
			int weight = best.first;
			int node = best.second;

			for (auto nbr : gr[node]) {
				if (weight + nbr.second < dist[nbr.first]) {
					//update
					auto f = st.find({dist[nbr.first], nbr.first});
					if (f != st.end())
						st.erase(f);
					dist[nbr.first] = weight + nbr.second;
					st.insert({dist[nbr.first], nbr.first});
				}
			}
		}

		return (dist[dest] == INT_MAX) ? -1 : dist[dest];
	}
};


int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		x--, y--;
		g.addEdge(x, y, w);
	}

	int x, y;
	cin >> x >> y;
	x--, y--;
	cout << g.dijkstra(x, y);

	return 0;
}