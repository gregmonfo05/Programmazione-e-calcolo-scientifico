#pragma once
#include <set>
#include <vector>
#include "unidirected_edge.h"
#include "unidirected_graph.h"
#include <map>
#include <limits>
#include <queue>




template<typename T>
struct PQ_Element {   // creo una struct per inserire nella priority queue la coppia (nodo, distanza dalla sorgente)
    T node;
	int distance;
	PQ_Element(const T& u, const int& d) {
		node = u;
		distance = d;
	}
    bool operator<(const PQ_Element& other) const {   // criterio di ordinamento nella priority queue
        return distance > other.distance; 
    }
};

template<typename T>
std::map<T,std::vector<T>> algoritmo_dijkstra(const unidirected_graph<T>& g, const T& source_node) 
{
	std::map<T,T> pred;     // mappa dei predecessori
	std::map<T,int> dist;   // mappa delle distanze dalla sorgente
	std::map<T,std::vector<T>> shortest_paths;      // creo una mappa (nodo, cammino sotto forma di sequenza di nodi visitati)
	
	const int INF = std::numeric_limits<int>::max();
			
	for (const auto& node:g.all_nodes()) {         
		dist[node] = INF;
	}
	
	pred[source_node] = source_node;
	dist[source_node] = 0;
	std::priority_queue<PQ_Element<T>> pq;
	for (const auto& node:g.all_nodes()) {      // inserisco tutte le coppie (nodo,distanza) nella coda con priorità
		pq.push(PQ_Element<T>(node, dist[node]));
	}
	
	while (!pq.empty()) {
		PQ_Element<T> pair = pq.top();
		pq.pop();
		T node = pair.node;
		int current_dist = pair.distance;
		if (current_dist > dist[node]) continue;    // se ho già salvato una distanza minore in dist significa che sto finendo di svuotare la queue anche se ho già trovato la distanza minima
		for (const auto& neighbour:g.neighbours(node)) {
			if (dist[neighbour] > dist[node] + 1) {    // peso pari a 1
				dist[neighbour] = dist[node] + 1;
				pred[neighbour] = node;
				pq.push(PQ_Element<T>(neighbour, dist[neighbour]));
			}
		}
	}
	
	for (const auto& node : g.all_nodes()) {
        if (dist[node] == INF) {    // Se il nodo non è raggiungibile dalla sorgente
			shortest_paths[node] = {};
		}
		else {
			T current = node;
			while (current != source_node) {
				shortest_paths[node].push_back(current);    // aggiungo il nodo corrente al vettore
				current = pred[current];    // current diventa il predecessore
			}
			shortest_paths[node].push_back(source_node);
			
			std::reverse(shortest_paths[node].begin(), shortest_paths[node].end());     // invertiamo il vettore
		}
    }
    
    return shortest_paths;
}