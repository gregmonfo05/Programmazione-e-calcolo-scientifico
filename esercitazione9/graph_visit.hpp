#pragma once
#include <set>
#include <vector>
#include "unidirected_edge.h"
#include "unidirected_graph.h"
#include "containers.hpp"
#include <map>

template<typename T>
unidirected_graph<T> graph_visit(const unidirected_graph<T>& g, const T& v, auto& c)
{
    std::set<T> set_nodes = g.all_nodes();
    std::map<T, bool> reached;
    unidirected_graph<T> visit_tree;
    for (const auto& node : set_nodes) {
        reached[node] = false;
    }
    reached[v] = true;
    for (const auto& neighbour : g.neighbours(v)) {    // metto in c i vicini di v prima di entrare nel while.
        unidirected_edge<T> f(v, neighbour);
        c.put(f);
    }
    while (!c.empty()) {
        unidirected_edge<T> e = c.get();
        T u;
		if (!reached[e.to()]) {   // siccome from e to dipendono dall'ordine lessicografico e non dall'ultimo nodo che ho visitato 
			u = e.to(); 
		}
		else if (!reached[e.from()]) {
			u = e.from();
		}
		else {
			continue;   // se li ho visitati entrambi passo al prossimo arco per evitare di creare archi in più nell'albero di visita
		}
		reached[u] = true;
        visit_tree.add_edge(e);
        std::vector<T> neighbours = g.neighbours(u);
        for (const auto& neighbour : neighbours) {
            if (!reached[neighbour]) {
                unidirected_edge<T> f(u, neighbour);
                c.put(f);
            }
        }
    }
    return visit_tree;
}


template<typename T>
void recursive_DFS(const unidirected_graph<T>& g, const T& node, std::map<T,bool>& reached, unidirected_graph<T>& visit_tree)
{	
	reached[node] = true;      // segno il nodo attuale come visitato
	std::vector<T> node_neighbours = g.neighbours(node);  // guardo i vicini del nodo
	for (const auto& w:node_neighbours) {   
		if (!reached[w]) {       // se non l'ho ancora visitato richiamo la funzione in modo ricorsivo
			unidirected_edge<T> e(node,w);
			visit_tree.add_edge(e);
			recursive_DFS(g, w, reached, visit_tree);
		}
	}
}



template<typename T>
unidirected_graph<T> recursive_DFS_support(const unidirected_graph<T>& g, const T& node)   // funzione di supporto in cui inizializzo le strutture dati per la funzione ricorsiva.
{
	std::set<T> set_nodes = g.all_nodes();
	std::map<T,bool> reached;
	unidirected_graph<T> visit_tree;
	for (const auto& v:set_nodes) {
		reached[v] = false;
	}
	recursive_DFS(g, node, reached, visit_tree);
	return visit_tree;
}
	