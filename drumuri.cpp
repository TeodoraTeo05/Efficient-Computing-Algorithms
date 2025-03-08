#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
#include <set>

using namespace std;

const unsigned long long INF = ULLONG_MAX;

struct DijkstraResult {
	vector<unsigned long long> dist;
	vector<unsigned long long> parent;
};

// algoritmul lui Dijkstra pentru a calcula distantele minime de la
// un nod sursa la toate celelalte noduri
DijkstraResult dijkstra(vector<pair<int, unsigned long long>> adj[],
						int nodes, int source) {
	// vectorul de distante de la sursa la fiecare nod
	vector<unsigned long long> d(nodes + 1, INF);
	// vectorul de parinti pentru a reconstrui drumul minim
	vector<unsigned long long> p(nodes + 1, 0);

	// set de prioritati pentru a extrage nodul cu distanta minima
	set<pair<unsigned long long, unsigned long long>> dij;

	d[source] = 0;
	dij.insert({d[source], source});

	while (!dij.empty()) {
		auto top = dij.begin();
		const auto [_, node] = *top;
		dij.erase(top);

		// parcurgem vecinii nodului curent si actualizam
		// distantele daca gasim un drum mai scurt
		for (const auto& [neigh, w] : adj[node]) {
			if (d[node] + w < d[neigh]) {
				dij.erase({d[neigh], neigh});

				d[neigh] = d[node] + w;
				p[neigh] = node;

				dij.insert({d[neigh], neigh});
			}
		}
	}

	// daca nu exista drum de la sursa la un nod, distanta este -1
	for (int node = 1; node <= nodes; node++) {
		if (d[node] == INF) {
			d[node] = -1;
		}
	}

	return {d, p};
}

int main() {
	ifstream fin("drumuri.in");
	ofstream fout("drumuri.out");

	unsigned long long n, m, x, y, z;
	fin >> n >> m;

	// vector de adiacenta pentru a retine muchiile si costurile
	vector<pair<int, unsigned long long>> adj[100005];
	for (int i = 0; i < m; i++) {
		unsigned long long a, b, c;
		fin >> a >> b >> c;
		adj[a].push_back({b, c});
	}

	fin >> x >> y >> z;
	DijkstraResult from_x = dijkstra(adj, n, x);
	DijkstraResult from_y = dijkstra(adj, n, y);
	// suma distantelor minime de la x la z si de la y la z
	unsigned long long result = from_x.dist[z] + from_y.dist[z];
	fout << result;

	fin.close();
	fout.close();

	return 0;
}
