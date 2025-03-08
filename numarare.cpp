#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int MOD = 1000000007;

// functia de sortare topologica a lui Kahn
vector<int> topologicalSort(int n, vector<vector<int>>& graph) {
	// vectorul de graduri de intrare pentru fiecare nod
	vector<int> top(n + 1, 0);
		// coada pentru a retine nodurile cu gradul de intrare 0
	queue<int> q;
	// vectorul de ordine a nodurilor
	vector<int> order;

	for (int i = 1; i <= n; i++) {
		for (int j : graph[i]) {
			top[j]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (top[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		order.push_back(node);
		// scadem gradul de intrare pentru vecinii nodului curent
		for (int i : graph[node]) {
			top[i]--;
			// daca gradul de intrare devine 0, adaugam nodul in coada
			if (top[i] == 0) {
				q.push(i);
			}
		}
	}
	// returnam ordinea nodurilor
	return order;
}

// construim graful comun dintre cele doua grafuri
vector<vector<int>> build(int n, vector<vector<int>>& graph1,
						  vector<vector<int>>& graph2) {
	vector<vector<int>> graph(n + 1);
	for (int i = 1; i <= n; i++) {
		// set cu vecinii comuni ai nodului i din primul graf
		set<int> common(graph1[i].begin(), graph1[i].end());
		// pentru fiecare vecin al nodului i din al doilea graf
		// verificam daca este comun cu nodul i din primul graf
		// si il adaugam in graful comun
			for (int j : graph2[i]) {
				if (common.count(j))
					graph[i].push_back(j);
			}
	}
	return graph;
}

// numaram numarul de drumuri de la nodul 1 la nodul n folosind
// programarea dinamica
int paths(int n, vector<int>& order, vector<vector<int>>& graph) {
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	// pentru fiecare nod in ordinea sortarii topologice
	// actualizam numarul de drumuri pentru vecinii sai
	for (int node : order) {
		for (int i : graph[node]) {
			dp[i] = (dp[i] + dp[node]) % MOD;
		}
	}
	// returnam numarul de drumuri de la nodul 1 la nodul n
	return dp[n];
}

int main() {
	ifstream fin("numarare.in");
	ofstream fout("numarare.out");

	// citim datele de intrare
	int n, m;
	fin >> n >> m;
	vector<vector<int>> graph1(n + 1), graph2(n + 1);

	for (int i = 0; i < m; i++) {
		int x, y;
		fin >> x >> y;
		graph1[x].push_back(y);
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		fin >> x >> y;
		graph2[x].push_back(y);
	}

	vector<vector<int>> common = build(n, graph1, graph2);
	vector<int> sort = topologicalSort(n, common);
	int result = paths(n, sort, common);

	fout << result << endl;

	fin.close();
	fout.close();

	return 0;
}
