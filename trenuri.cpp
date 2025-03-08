#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

// sortarea topologica a unui graf cu algoritmul lui Kahn
vector<string> topologicalSort(unordered_map<string, int>& obs,
								unordered_map<string, vector<string>>& graph) {
	// coada pentru a retine nodurile cu gradul de intrare 0
	queue<string> q;
	// vectorul de ordine a nodurilor
	vector<string> order;

	// adaugam nodurile cu gradul de intrare 0 in coada
	for (const auto& node : obs) {
		if (node.second == 0) {
			q.push(node.first);
		}
	}

	while (!q.empty()) {
		string current = q.front();
		q.pop();
		order.push_back(current);
		// daca nodul curent are vecini, scadem gradul de intrare
		// al vecinilor si daca acesta devine 0, il adaugam in coada
		if (graph.find(current) != graph.end()) {
			for (const string& neighbor : graph.at(current)) {
				obs[neighbor]--;
				if (obs[neighbor] == 0) {
					q.push(neighbor);
				}
			}
		}
	}
	// returnam ordinea nodurilor
	return order;
}

int main() {
	ifstream fin("trenuri.in");
	ofstream fout("trenuri.out");

	string source, destination;
	fin >> source >> destination;

	int m;
	fin >> m;

	// graful reprezentat ca un dictionar de liste de adiacenta
	unordered_map<string, vector<string>> graph;
	// dictionar pentru a retine gradul de intrare al fiecarui nod
	unordered_map<string, int> obs;
	// dictionar pentru a retine numarul maxim de orase vizitate
	unordered_map<string, int> max_visited;
	// variabile pentru orasele de la care si la care se doreste sa se ajunga
	string to, from;

	for (int i = 0; i < m; i++) {
		fin >> from >> to;
		// adauga traseul in graf si incrementeaza gradul de intrare al destinatiei
		graph[from].push_back(to);
		obs[to]++;
		// daca orasul de plecare nu are niciun traseu,
		// seteaza gradul de intrare la 0
		if (!obs.count(from)) {
			obs[from] = 0;
		}
	}

	// sortam topologic graful si calculam numarul maxim de orase vizitate
	vector<string> order_cities = topologicalSort(obs, graph);
	// setam numarul maxim de orase vizitate pentru orasul sursa
	max_visited[source] = 1;
	for (const string& city : order_cities) {
		// pentru fiecare oras, actualizam numarul maxim de orase vizitate
		if (max_visited.find(city) != max_visited.end()) {
			int current = max_visited[city];
			// pentru fiecare vecin al orasului, actualizam numarul
			// maxim de orase vizitate
			for (const string& neighbor : graph[city]) {
				max_visited[neighbor] = max(max_visited[neighbor], current + 1);
			}
		}
	}

	fout << max_visited[destination];

	fin.close();
	fout.close();
	return 0;
}
